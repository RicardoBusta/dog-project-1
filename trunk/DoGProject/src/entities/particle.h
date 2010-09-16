/*
 * Particle.h
 *
 *  Created on: 16/09/2010
 *      Author: ricardo
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "entity.h"

class Particle: public Entity {
public:
	Particle(Entity* parent=NULL);
	virtual ~Particle();

	void draw();
	void handleSelf();
};

#endif /* PARTICLE_H_ */
