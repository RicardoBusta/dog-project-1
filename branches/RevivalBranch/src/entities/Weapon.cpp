/*
 * weapon.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "Weapon.h"

#include "../contents/model/ModelBullet.h"
#include "../contents/model/ModelWeapon.h"
#include "../contents/model/ModelShip.h"

Weapon::Weapon(Entity* p):Entity(p) {

}

Weapon::~Weapon() {
}

Projectile* Weapon::shoot(){
	Projectile *p = new Projectile( Vector3(0,0,-23) , parent->getParent());
	p->setFrame(parent->getFrame()^getFrame());
	ModelWeapon *lol = new ModelWeapon();
	lol->setSkin(1);
	//p->setModel(new ModelBullet());
	p->setModel(lol);
	return p;
}

void Weapon::handler(){
	rotateZ(5);
}
