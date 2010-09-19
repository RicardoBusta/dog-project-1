/*
 * texture.cpp
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#include "texture.h"

// identificador do content e caminho da textura
Texture::Texture(std::string label, std::string path)
{
	this->setLabel(label);
	this->setType(CONTENT_TEXTURE);
	handle = 0;
	if(!path.compare(""))
		this->load(path);
}

Texture::~Texture()
{
	SDL::removeTexture(1, &handle);
}

bool Texture::load(std::string &path)		// Carrega textura
{
	handle = SDL::loadTexture(path.c_str());
	if(handle)
	{
		return true;
	}
	return false;
	// PODE SETAR O ACTIVE AQUI???
}

GLuint Texture::getHandle()
{
	return handle;
}

