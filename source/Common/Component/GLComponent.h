#pragma once
#ifndef _GL_COMPONENT_H_
#define _GL_COMPONENT_H_

#include <iostream>
#include <vector>
#include "glm/glm.hpp"

class GLComponent
{
public:
	GLComponent();
	~GLComponent();

private:
	//�㼶��ϵ
	GLComponent * _parent;
	std::vector<GLComponent *> _children;
	
	//�Ƿ��游�������
	bool _destroyWithParent;

	//λ��
	glm::vec3 _localPosition;

public:
	virtual void setDestroyWithParent(bool value)
	{
		_destroyWithParent = value;
	}

	virtual bool needDestroyWithParent()
	{
		return _destroyWithParent;
	}

	virtual void attach(GLComponent * parent);
	virtual void addChild(GLComponent * child);
	virtual void removeChild(GLComponent * child);

	virtual void setLocalPosition(glm::vec3 position)
	{
		_localPosition = position;
	}

	virtual void draw() {}
};

#endif