/*
 * projectile.h
 *
 *  Created on: 16/09/2010
 *      Author: ricardo
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Particle.h"

class Projectile: public Particle {
public:
	Projectile(Vector3 direction, Entity* parent=NULL);
	virtual ~Projectile();
	void handler();

	Vector3 *direction;
	int lifeTime;
};

#endif /* PROJECTILE_H_ */
