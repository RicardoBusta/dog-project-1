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

	void draw();
};

#endif /* MODELBULLET_H_ */
