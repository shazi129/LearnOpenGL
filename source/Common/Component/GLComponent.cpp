#include "./GLComponent.h"

using namespace std;

GLComponent::GLComponent()
	: _parent(nullptr),
	_destroyWithParent(false)
{
}

GLComponent::~GLComponent()
{
	for (int i = 0; i < _children.size(); i++)
	{
		if (_children[i]->needDestroyWithParent())
		{
			delete _children[i];
		}
	}
}

void GLComponent::attach(GLComponent * parent)
{
	if (parent != nullptr)
	{
		_parent = parent;
		_parent->addChild(this);
	}
}

void GLComponent::addChild(GLComponent * child)
{
	if (child != nullptr)
	{
		for (int i = 0; i < _children.size(); i++)
		{
			if (_children[i] == child)
			{
				return;
			}
		}
		_children.push_back(child);
	}
}

void GLComponent::removeChild(GLComponent * child)
{
	vector<GLComponent*>::iterator iter = _children.begin();
	while (iter != _children.end())
	{
		if (child == *iter)
		{
			_children.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}