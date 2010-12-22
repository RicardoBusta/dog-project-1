/*
 * hero.cpp
 *
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#include "Hero.h"
#include "../contents/ContentManager.h"
#include "../contents/model/ModelWeapon.h"
#include "../entities/Weapon.h"

Hero::Hero(Entity* p):Entity(p) {
	entityType = ENTITY_PLAYER;
	shootCoolDown = 0;
	speed = 5;
	this->addBoundings(new BoundingBox
					(this->getPosition(),122.0f,50.0f,150.0f, *this));		// CREATES A BOUNDING AND ADD IT
}

Hero::~Hero() {
}

void Hero::addAction( ControllerStatus control ){

}

void Hero::handler()
{
	if(shootCoolDown>=0)
		shootCoolDown--;
}

void Hero::moveForward(){
	move( Vector3(0,0,-speed) );
}
void Hero::moveBackward(){
	move( Vector3(0,0,speed) );
}
void Hero::moveLeft(){
	move( Vector3(-speed,0,0) );
	if(getRotationZ() < 45 ){
		rotateZ(2);
	}
}
void Hero::moveRight(){
	move( Vector3(speed,0,0) );
	if(getRotationZ() > -45 ){
		rotateZ(-2);
	}
}
void Hero::handleTilt(){
	float tiltspeed=2;
	if(getRotationZ() > tiltspeed){
		rotateZ(-tiltspeed);
	}else if(getRotationZ() < -tiltspeed){
		rotateZ(tiltspeed);
	}else{
		setRotationZ(0);
	}
}

void Hero::handleShoot(list<Entity*> *bullets){
	if (shootCoolDown<=0){
		//model->skin = 1 - model->skin;
		list<Weapon*>::iterator it;
		for(it=weapons.begin();it!=weapons.end();it++){
			(*it)->shoot(bullets);
		}
		shootCoolDown = 10;

		//TODO remodelar de forma que não seja necessário fazer esse cast
		SoundEffect *tiro = reinterpret_cast<SoundEffect *>(ContentManager::getContent(CONTENT_SOUND, "tiro"));
		tiro->play(PLAY_ONCE);
	}
}

void Hero::addWeapon( Vector3 v ){
	Weapon *weapon = new Weapon(this);
	weapons.push_back(weapon);
	weapon->move(v);
	Model* weapon_model = new ModelWeapon();
	weapon_model->setSkin(model->skin);
	weapon->setModel(weapon_model);
}
