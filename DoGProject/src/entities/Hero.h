/*
 * hero.h
 *	The main hero ship
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#ifndef HERO_H_
#define HERO_H_

#include "Entity.h"

class Weapon;

class Hero : public Entity
{
private:
	// The main "reaction" function
	void handler();
public:
	Hero(Entity* parent=NULL);
	~Hero();

	void addAction( ControllerStatus control );

	//Shooting CoolDown
	int shootCoolDown;

	//temp
	void addWeapon(const btVector3 &position );
	list<Weapon*> weapons;

	//Moving
	float speed;
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void handleTilt();
	void handleShoot(list<Entity*> *bullets);
};

#endif /* HERO_H_ */
