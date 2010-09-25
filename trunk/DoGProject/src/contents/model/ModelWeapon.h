/*
 * ModelWeapon.h
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#ifndef MODELWEAPON_H_
#define MODELWEAPON_H_

#include "../model.h"

class ModelWeapon: public Model {
public:
	ModelWeapon();
	virtual ~ModelWeapon();

	float r, l;

	void middleTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	void borderTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	void draw();
};

#endif /* MODELWEAPON_H_ */
