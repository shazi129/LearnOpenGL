#pragma once
#ifndef _SHADER_H_
#define _SHADER_H_

#include <iostream>

class GLShader
{
private:
	unsigned int _program;

	bool getFileString(const std::string filePath, std::string& outString);

public:
	GLShader();
	~GLShader();

	bool init(const std::string& vetexShaderPath, const std::string fragShaderPath);

	void use();
	// uniform¹¤¾ßº¯Êý
	void setBool(const std::string &name, bool value);
	void setInt(const std::string &name, int value);
	void setFloat(const std::string &name, float value);
};

#endif // !_SHADER_H_
