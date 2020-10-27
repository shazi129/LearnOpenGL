#pragma once

#ifndef _OPENGL_TEXTURE_H_
#define _OPENGL_TEXTURE_H_

#include "GLComponent.h"
#include "GLShader.h"

class GLTexture : public GLComponent
{
public:
	GLTexture(std::string textureFilePath, int width, int height);

};

#endif
