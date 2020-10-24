#pragma once
#ifndef _MY_WINDOWN_H_
#define _MY_WINDOWN_H_

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

class MyWindow
{
private:
	GLFWwindow* _window;

	int _width;
	int _height;
	std::string _title;

	glm::vec4 _clearColor;

public:
	MyWindow(int width, int height, const std::string& title);

	void setClearColor(glm::vec4 clearColor);

protected:
	virtual void init();
	virtual int createWindow();
	virtual void draw();

public:

	virtual void show();

	static void  frameBufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
