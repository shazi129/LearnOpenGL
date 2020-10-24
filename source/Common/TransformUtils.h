#pragma once
#ifndef _TRANSFORM_UTILS_H_
#define _TRANSFORM_UTILS_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 getTranslateMatrix(glm::vec3 tranVec)
{
	return glm::mat4(
		1.0f, 0.0f, 0.0f, tranVec.x,
		0.0f, 1.0f, 0.0f, tranVec.y,
		0.0f, 0.0f, 1.0f, tranVec.z,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

glm::mat4 getScaleMatrix()
{
	return glm::mat4();
}

glm::mat4 getRoateMatrix()
{
	return glm::mat4();
}

glm::mat4 getMVPMatrix()
{
	return glm::mat4();
}

#endif