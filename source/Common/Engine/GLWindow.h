#pragma once
#ifndef _MY_WINDOWN_H_
#define _MY_WINDOWN_H_

#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

#include "Component/GLComponent.h"

class GLWindow
{
private:
	GLFWwindow* _window;

	int _width;
	int _height;
	std::string _title;

	glm::vec4 _clearColor;

	std::function<void()> _externalDraw;
	std::function<void()> _windowEndCallback;

	GLComponent * _root;

public:
	GLWindow(int width, int height, const std::string& title);

	void setClearColor(glm::vec4 clearColor);

	void OnDraw(std::function<void()> func);

	void OnDispose(std::function<void()> func)
	{
		_windowEndCallback = func;
	}

protected:
	virtual void init();
	virtual int createWindow();
	virtual void draw();

public:

	virtual void show();

	static void  frameBufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
