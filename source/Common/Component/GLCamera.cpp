#pragma once
#include "GLCamera.h"
#include "TransformUtils.h"

glm::mat4 GLCamera::GetOthroMatrix()
{
	glm::mat4 trans(1.0f);

	//中心点移到原点
	glm::vec3 center = (_far - _near) / 2 * _lookAt + getWorldPosition();
	trans = TransformUtils::getTranslateMatrix(-center) * trans;

	//lookat旋转到z的负方向，up旋转到y方向
	trans = TransformUtils::GetAixsRooteMatrix(_lookAt, _up) * trans;

	//缩放到[-1, 1]
	glm::vec3 scale = glm::vec3(1 / _othroWidth, 1, 1/(_far - _near));
	trans = TransformUtils::getScaleMatrix(scale) * trans;

	return trans;
}

glm::mat4 GLCamera::GetPerspectiveMatrix()
{
	glm::mat4 trans(1.0f);

	return trans;
}