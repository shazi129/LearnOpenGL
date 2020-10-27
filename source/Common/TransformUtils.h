#pragma once
#ifndef _TRANSFORM_UTILS_H_
#define _TRANSFORM_UTILS_H_

#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

std::string mat4ToString(glm::mat4 mat)
{
	std::stringstream ss;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ss << mat[i][j] << "\t";
		}
		ss << "\n";
	}
	return ss.str();
}

glm::mat4 getTranslateMatrix(glm::vec3 tranVec)
{
	return glm::mat4(
		1.0f, 0.0f, 0.0f, tranVec.x,
		0.0f, 1.0f, 0.0f, tranVec.y,
		0.0f, 0.0f, 1.0f, tranVec.z,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

glm::mat4 getScaleMatrix(glm::vec3 scaleVec)
{
	return glm::mat4(
		scaleVec.x,  0.0f,        0.0f,       0.0f,
		0.0f,        scaleVec.y,  0.0f,       0.0f,
		0.0f,        0.0f,        scaleVec.z, 0.0f,
		0.0f,        0.0f,        0.0f,        1.0f
	);
}

glm::mat4 getRoateZMatrix(float randian)
{
	return glm::mat4(
		cos(randian), -sin(randian), 0.0f, 0.0f,
		sin(randian), cos(randian),  0.0f, 0.0f,
		0.0f,          0.0f,           1.0,  0.0f,
		0.0f,          0.0f,           0.0f, 1.0f
	);
}

glm::mat4 getRoateYMatrix(float randian)
{
	return glm::mat4(
		cos(randian),  0.0f, sin(randian),  0.0f,
		0.0f,           1.0f, 0.0f,           0.0f,
		-sin(randian), 0.0f, cos(randian),  0.0f,
		0.0f,           0.0f, 0.0f,           1.0f
	);
}

glm::mat4 getRoateXMatrix(float randian)
{
	return glm::mat4(
		1.0f, 0.0f,          0.0f,           0.0f,
		0.0f, cos(randian), -sin(randian), 0.0f,
		0.0f, sin(randian), cos(randian),  0.0f,
		0.0f, 0.0f,          0.0f,           1.0f
	);
}

glm::mat4 getMVPMatrix()
{
	return glm::mat4();
}

#endif