#pragma once

#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include <fstream>
#include <sstream>

#include "GLShader.h"



using namespace std;

GLShader::GLShader()
{
	

}

GLShader::~GLShader()
{
	if (_program > 0)
	{
		glDeleteProgram(_program);
	}
}

bool GLShader::init(const std::string& vertexShaderPath, const std::string fragShaderPath)
{
	string vertexSource;
	if (!getFileString(vertexShaderPath, vertexSource))
	{
		return false;
	}

	string fragSource;
	if (!getFileString(fragShaderPath, fragSource))
	{
		return false;
	}
	
	//编译定点着色器
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar * vertexCode = vertexSource.c_str();
	glShaderSource(vertexShader, 1, &vertexCode, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

	//编译片元着色器
	int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar * fragCode = fragSource.c_str();
	glShaderSource(fragShader, 1, &fragCode, NULL);
	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

	//链接
	_program = glCreateProgram();
	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragShader);
	glLinkProgram(_program);
	// check for linking errors
	glGetProgramiv(_program, GL_LINK_STATUS, &success);
	if (!success) 
	{
		glGetProgramInfoLog(_program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return false;
	}

	return true;
}

void GLShader::use()
{
	glUseProgram(_program);
}

// uniform工具函数
void GLShader::setBool(const string &name, bool value)
{
	glUniform1i(glGetUniformLocation(_program, name.c_str()), (int)value);
}

void GLShader::setInt(const string &name, int value)
{
	glUniform1i(glGetUniformLocation(_program, name.c_str()), value);
}

void GLShader::setFloat(const string &name, float value)
{
	glUniform1f(glGetUniformLocation(_program, name.c_str()), value);
}

bool GLShader::getFileString(const std::string filePath, std::string& outString)
{
	ifstream ifs;
	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		std::stringstream ss;

		ifs.open(filePath.c_str());
		ss << ifs.rdbuf();
		ifs.close();

		outString = ss.str();

		return true;
	}
	catch (ifstream::failure e)
	{
		cout << "Shader::read file[" << filePath.c_str() << "] error." << endl;
		return false;
	}
}