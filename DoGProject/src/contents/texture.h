/*
 * texture.h
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL/SDL_opengl.h>
#include "content.h"

class Texture: public Content {
public:
	Texture(std::string label, std::string path = "");	// identificador do content e caminho da textura
	bool load(std::string &path);						// Carrega textura
	GLuint getHandle();
	virtual ~Texture();


private:
	GLuint handle;	// handle para o identificador da textura
};

#endif /* TEXTURE_H_ */
