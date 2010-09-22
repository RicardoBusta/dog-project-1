/*
 * weapon.h
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include "entity.h"
#include "projectile.h"

class Weapon: public Entity {
public:
	Weapon(Entity* parent=NULL);
	virtual ~Weapon();

	void shoot(list<Entity*> *bullets);

	void handler();
};

#endif /* WEAPON_H_ */
