/*
 * texture.h
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "content.h"

class Texture: public Content {
public:
	Texture();
	virtual ~Texture();

	bool load();
};

#endif /* TEXTURE_H_ */
