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
	// TODO Auto-generated constructor stub

}

Weapon::~Weapon() {
	// TODO Auto-generated destructor stub
}

void Weapon::shoot(list<Entity*> *bullets){
	Projectile *p = new Projectile( btVector3(0,0,-10) , parent->getParent());
	btTransform a(parent->getFrame());
	a *= getFrame();
	p->setFrame(a);
	ModelWeapon *lol = new ModelWeapon();
	lol->setSkin(1);
	//p->setModel(new ModelBullet());
	p->setModel(lol);
	bullets->push_back(p);
}

void Weapon::handler(){
	//rotate(0, 0, 5);
}
