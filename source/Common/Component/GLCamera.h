#pragma once

#ifndef _GL_CAMERA_H_
#define _GL_CAMERA_H_

class GLCamera : GLComponent
{
public:
	//透视模式
	enum PROJECTION_MODE
	{
		PERSPECTIVE,
		OTHROGRAPHIC
	};

private:

	PROJECTION_MODE _projection = PERSPECTIVE;

	//朝向
	glm::vec3 _lookAt;
	//向上的方向
	glm::vec3 _up;

	//近平面和远平面
	float _near;
	float _far;

	//宽高比
	float _aspect;

	//正交投影宽度
	float _othroWidth;

	//视角
	float _FOV;

public:

	void LookAt(glm::vec3 upDirection, glm::vec3 lookDirection);

	void SetNear(float near);
};

#endif
