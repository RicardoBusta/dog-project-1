/*
 * entity.cpp
 *
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#include "entity.h"
#include "../base/sdl.h"

Entity::Entity(Entity* p) {
	parent = p;
	if(parent != NULL){
		parent->sons.push_back(this);
	}

	visible = true;
	frozen = false;
	live = true;

	//setPosition(0,0,0);
	//setRotation(0,0,0);
	//setScale(1,1,1);

	// Set white the color
	setColor(1.0f,1.0f,1.0f);
}

Entity::~Entity() {
	//killSons();
}

void Entity::handle(){
	//If it's state isn't frozen
	if(!frozen){
		//Handle itself
		this->handleSelf();

		//Handle children
		list<Entity*>::iterator it;
		for(it = sons.begin(); it!=sons.end(); it++){
			(*it)->handle();
		}
	}
}

void Entity::killSons(){
//this
	list<Entity*>::iterator it;
	while (!sons.empty()){
		it = sons.begin();
		delete (*it);
		sons.pop_front();
	}
	sons.clear();
}

void Entity::setPosition( Point3 position )
{
	//Set the position of the object
	coords.getOrigin()->setXYZ( position );
}

void Entity::move( Vector3 delta ){
	//Translate the model from it's current coordinates
	coords.moveOriginT( delta );
}

Point3* Entity::getPosition(){
	return coords.getOrigin();
}

void Entity::setRotation(float x, float y, float z)
{
	//Set the rotation of the object
	this->coords.setRotationX( (int)(x*16.0f) );
	this->coords.setRotationY( (int)(y*16.0f) );
	this->coords.setRotationZ( (int)(z*16.0f) );
}

void Entity::rotate(float x, float y, float z)
{
	//Rotates the object based on the current position
	this->coords.setRotationX( this->coords.getRotationX() + (int)(x*16.0f) );
	this->coords.setRotationY( this->coords.getRotationY() + (int)(y*16.0f) );
	this->coords.setRotationZ( this->coords.getRotationZ() + (int)(z*16.0f) );
}

void Entity::setScale(float x, float y, float z)
{
	//Set the object scale
	this->scale.x = x;
	this->scale.y = y;
	this->scale.z = z;
}

void Entity::resize(float x, float y, float z)
{
	//Scales the current object size
	this->scale.x += x;
	this->scale.y += y;
	this->scale.z += z;
}

void Entity::setColor(float r, float g, float b)
{
	//Set the object color
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
}

void Entity::toggleVisible()
{
	this->visible = !this->visible;
}

void Entity::toggleLive()
{
	this->live = !this->live;
}

void Entity::toggleFrozen()
{
	this->frozen = !this->frozen;
}

void Entity::render()
{
	//Prepare the coordinate system
	glPushMatrix();
	glMultMatrixf( coords.getMatrixToWorld() );

	//Draw the entity and it's children if it isn't invisible
	if(visible){
		//Draw this object
		this->draw();

		//Render the object's children
		list<Entity*>::iterator it;
		for(it = sons.begin(); it!=sons.end(); it++){
			(*it)->render();
		}
	}
	glPopMatrix();
}

bool Entity::isLive(){
	return live;
}

bool Entity::isVisible(){
	return visible;
}

bool Entity::isFrozen(){
	return frozen;
}
