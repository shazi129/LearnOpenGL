#pragma once

#ifndef _GL_CAMERA_H_
#define _GL_CAMERA_H_

class GLCamera : GLComponent
{
public:
	//͸��ģʽ
	enum PROJECTION_MODE
	{
		PERSPECTIVE,
		OTHROGRAPHIC
	};

private:

	PROJECTION_MODE _projection = PERSPECTIVE;

	//����
	glm::vec3 _lookAt;
	//���ϵķ���
	glm::vec3 _up;

	//��ƽ���Զƽ��
	float _near;
	float _far;

	//��߱�
	float _aspect;

	//����ͶӰ���
	float _othroWidth;

	//�ӽ�
	float _FOV;

public:

	void LookAt(glm::vec3 upDirection, glm::vec3 lookDirection);

	void SetNear(float near);
};

#endif
