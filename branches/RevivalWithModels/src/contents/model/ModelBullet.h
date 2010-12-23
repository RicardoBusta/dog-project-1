/*
 * ModelBullet.h
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#ifndef MODELBULLET_H_
#define MODELBULLET_H_

#include "../Model.h"

class ModelBullet: public Model {
public:
	ModelBullet();
	virtual ~ModelBullet();

	void triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);

	void draw();
};

#endif /* MODELBULLET_H_ */
