/*
 * weapon.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "weapon.h"

#include "../contents/ModelBullet.h"

Weapon::Weapon(Entity* p):Entity(p) {
	// TODO Auto-generated constructor stub

}

Weapon::~Weapon() {
	// TODO Auto-generated destructor stub
}

void Weapon::shoot(list<Entity*> *bullets){
	Projectile *p = new Projectile( Vector3(0,0,-10) , parent->getParent());
	p->setFrame(parent->getFrame()^getFrame());
	p->setModel(new ModelBullet());
	bullets->push_back(p);
}

void Weapon::handler(){
	rotateZ(5);
}
