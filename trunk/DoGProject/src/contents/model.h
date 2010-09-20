/*
 * model.h
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#ifndef MODEL_H_
#define MODEL_H_

#include "content.h"

#include "../base/sdl.h"
#include "../math/frame.h"
#include "../math/point3.h"
#include "../math/vector3.h"
#include "../base/util.h"
#include "../contents/contentmanager.h"

class Model: public Content {
public:
	Model();
	virtual ~Model();

	virtual void draw()=0;

	bool load(std::string &);
};

#endif /* MODEL_H_ */
