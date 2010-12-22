/*
 * ModelShip.h
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

//TODO when the model class is working properly, this one will not be needed anymore

#ifndef MODELSHIP_H_
#define MODELSHIP_H_

#include "../Model.h"

class ModelShip: public Model {
public:
	ModelShip();
	virtual ~ModelShip();

	void triangle(float,float,float,float,float,float,float,float,float);

	void draw();
};

#endif /* MODELSHIP_H_ */
