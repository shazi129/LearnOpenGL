#pragma once

#include "./GLWindow.h"

using namespace std;

GLWindow::GLWindow(int width, int height, const std::string& title)
	: _width(width),
	  _height(height),
	  _title(title),
	  _externalDraw(nullptr), _windowEndCallback(nullptr)
{
	_clearColor = glm::vec4(0.2f, 0.3f, 0.3f, 1.0f);

	init();

	if (createWindow() != 0)
	{
		_window = nullptr;
		glfwTerminate();
	}
}

void GLWindow::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void GLWindow::frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int GLWindow::createWindow()
{
	// glfw window creation
	// --------------------
	_window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
	if (_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, frameBufferSizeCallback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	return 0;
}

void GLWindow::setClearColor(glm::vec4 clearColor)
{
	_clearColor = clearColor;
}

void GLWindow::OnDraw(std::function<void()> func)
{
	_externalDraw = func;
}

void GLWindow::draw()
{

}

void GLWindow::show()
{
	if (!_window)
	{
		return;
	}

	while (!glfwWindowShouldClose(_window))
	{
		if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(_window, true);
		}

		glClearColor(_clearColor.r, _clearColor.g, _clearColor.b, _clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT);

		if (_externalDraw)
		{
			_externalDraw();
		}
		else
		{
			draw();
		}

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	if (_windowEndCallback)
	{
		_windowEndCallback();
	}

	glfwTerminate();
}