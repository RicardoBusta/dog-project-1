/*
 * entity.cpp
 *
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#include "entity.h"
#include "../base/sdl.h"

Entity::Entity() {
	visible = false;
	frozen = true;
	live = true;

	//setPosition(0,0,0);
	//setRotation(0,0,0);
	//setScale(1,1,1);

	// Set white the color
	setColor(1.0f,1.0f,1.0f);
}

Entity::~Entity() {
	killSons();
}

void Entity::handle(){

	// This entity react
	this->handleSelf();

	// Propagate the reaction to its sons
	list<Entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		(*it)->handleSelf();
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
//or this
	//list<entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		delete (*it);
	}
	sons.clear();
}

void Entity::setPosition( Point3 position )
{
	// Changes the entity center position
	coords.getOrigin()->setPosition( position );
}

void Entity::move( Vector3 delta ){
	// Translate the model
	coords.moveOriginT( delta );
}

void Entity::setRotation(float x, float y, float z)
{
	this->coords.setRotationX( (int)(x*16.0f) );
	this->coords.setRotationY( (int)(y*16.0f) );
	this->coords.setRotationZ( (int)(z*16.0f) );
}

void Entity::rotate(float x, float y, float z)
{
	this->coords.setRotationX( this->coords.getRotationX() + (int)(x*16.0f) );
	this->coords.setRotationY( this->coords.getRotationY() + (int)(y*16.0f) );
	this->coords.setRotationZ( this->coords.getRotationZ() + (int)(z*16.0f) );
}

void Entity::setScale(float x, float y, float z)
{
	this->scale.x = x;
	this->scale.y = y;
	this->scale.z = z;
}

void Entity::resize(float x, float y, float z)
{
	this->scale.x += x;
	this->scale.y += y;
	this->scale.z += z;
}

void Entity::setColor(float r, float g, float b)
{
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
	//glMatrixMode( GL_MODELVIEW );

	// Prepare the coordinate system
	glPushMatrix();
	glMultMatrixf( coords.getMatrixToWorld() );

	// The Proper drawing
	this->draw();

	// Render the sons
	list<Entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		(*it)->render();
	}

	// Return the state of the opengl matrix
	glPopMatrix();
}
