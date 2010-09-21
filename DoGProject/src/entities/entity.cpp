/*
 * entity.cpp
 *
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#include "entity.h"
#include "../base/sdl.h"
#include "../contents/model.h"
Entity::Entity(Entity* p) {
	parent = p;
	if(parent != NULL){
		parent->sons.push_back(this);
	}

	visible = true;
	frozen = false;
	live = true;
	model = NULL;
	setPosition( Point3(0,0,0) );
	setRotation(0,0,0);
	setScale(1,1,1);
	// Set white the color
	setColor(1.0f,1.0f,1.0f);
}

Entity::~Entity() {
	//killSons();
}

Entity* Entity::getParent(){
	return parent;
}

void Entity::handle(){
	//If it's state isn't frozen
	if(!frozen){
		//Handle itself
		this->handler();

		//Handle children
		list<Entity*>::iterator it;
		for(it = sons.begin(); it!=sons.end(); it++){
			if( (*it)->isLive() ){
			(*it)->handle();
			}else{
				list<Entity*>::iterator it2;
				it2 = it;
				it--;
				delete (*it2);
				sons.erase(it2);
			}
		}
	}
}

void Entity::clearChildren(){
//this
	list<Entity*>::iterator it;
	while (!sons.empty()){
		it = sons.begin();
		delete (*it);
		sons.pop_front();
	}
	sons.clear();
}

void Entity::setModel(Model* m){
	model = m;
}

void Entity::setPosition( Point3 position )
{
	//Set the position of the object
	coords.getOrigin()->setXYZ( position );
}

void Entity::moveSelf( Vector3 delta ){
	//Translate the model from it's current coordinates
	coords.moveOriginT( delta );
}

void Entity::move( Vector3 delta ){

	//Translate the model in the world coordinates
	coords.moveOriginW( delta );
}

Point3* Entity::getPosition(){
	return coords.getOrigin();
}

void Entity::setRotation(float x, float y, float z)
{
	//Set the rotation of the object
	this->coords.setRotationX( x );
	this->coords.setRotationY( y );
	this->coords.setRotationZ( z );
}

void Entity::setRotationX(float n){
	this->coords.setRotationX( n );
}

void Entity::setRotationY(float n){
	this->coords.setRotationY( n );
}

void Entity::setRotationZ(float n){
	this->coords.setRotationZ( n );
}

void Entity::rotate(float x, float y, float z){
	//Rotates the object based on the current position
	this->coords.rotateX( x );
	this->coords.rotateY( y );
	this->coords.rotateZ( z );
}

void Entity::rotateX(float n){
	this->coords.rotateX(n);
}

void Entity::rotateY(float n){
	this->coords.rotateY(n);
}

void Entity::rotateZ(float n){
	this->coords.rotateZ(n);
}

float Entity::getRotationX(){
	return this->coords.getRotationX();
}

float Entity::getRotationY(){
	return this->coords.getRotationY();
}

float Entity::getRotationZ(){
	return this->coords.getRotationZ();
}
void Entity::setScale(float x, float y, float z){
	//Set the object scale
	this->scale.x = x;
	this->scale.y = y;
	this->scale.z = z;
}

void Entity::resize(float x, float y, float z){
	//Scales the current object size
	this->scale.x += x;
	this->scale.y += y;
	this->scale.z += z;
}

void Entity::setColor(float r, float g, float b){
	//Set the object color
	this->color.r = r;
	this->color.g = g;
	this->color.b = b;
}

void Entity::toggleVisible(){
	this->visible = !this->visible;
}

void Entity::toggleLive(){
	this->live = !this->live;
}

void Entity::toggleFrozen(){
	this->frozen = !this->frozen;
}

void Entity::render(){
	//Prepare the coordinate system
	glPushMatrix();
	glMultMatrixf( coords.getMatrixToWorld() );

	//Draw the entity and it's children if it isn't invisible
	if(visible){
		//Draw this object
		glColor3f(color.r,color.g,color.b);
		if(model!=NULL){
			this->model->draw();
		}


		//Render the object's children
		list<Entity*>::iterator it;
		for(it = sons.begin(); it!=sons.end(); it++){
			(*it)->render();
		}
	}
	glPopMatrix();
}

bool Entity::isLive() const{
	return live;
}

bool Entity::isVisible() const{
	return visible;
}

bool Entity::isFrozen() const{
	return frozen;
}

void Entity::handler(){

}
