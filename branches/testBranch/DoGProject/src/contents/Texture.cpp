/*
 * texture.cpp
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#include "Texture.h"
#include "../contents/ContentManager.h"

// identificador do content e caminho da textura
Texture::Texture(std::string label, std::string path)
	:Content(label,CONTENT_TEXTURE), handle(0)
{
	if(path != "")
		this->load(path);

	ContentManager::addContent(this);
	printf("Textura carregada com label: %s\n", this->getLabel().c_str());
	printf("E com handle: %d\n", this->getHandle());
}

Texture::~Texture()
{
	SDL::removeTexture(1, &handle);
}

bool Texture::load(std::string &path)		// Carrega textura
{
	string completePath = TEXTURESPATH;
	completePath.append(path);
	cout << completePath << endl;
	handle = SDL::loadTexture(completePath.c_str());
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

void Texture::bind(){
	glBindTexture(GL_TEXTURE_2D, getHandle());
}
