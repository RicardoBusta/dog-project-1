/*
 * entity.cpp
 *
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#include "Entity.h"
#include "../base/SDL.h"
#include "../contents/Model.h"

Entity::Entity(Entity* p)
{
	coords.setIdentity();
	parent = p;
	if(parent != NULL){
		parent->sons.push_back(this);
	}
	visible = true;
	frozen = false;
	live = true;
	model = NULL;
	setPosition(btVector3(0, 0, 0));
	setColor(1.0f,1.0f,1.0f);
}

Entity::~Entity() {
	//killSons();
	std::list<BoundingVolume *>::iterator iter;
	
	for(iter = boundings.begin(); iter != boundings.end(); ++iter)
	{
		PhysicsSystem::deleteVolume(*iter);
	}
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

void Entity::setPosition( const btVector3 &displacement ){
	//Set the position of the object
	coords.setOrigin(displacement);
	//ADDED
	translateBoundings();
}

const btVector3& Entity::getPosition(){
	return coords.getOrigin();
}

void Entity::move(const btVector3 &delta){
	
	//Translate the model in the world coordinates
	coords.setOrigin(coords.getOrigin() + delta);
	// ADDED
	translateBoundings();
}

void Entity::rotate(const btVector3 &direction, btScalar angle)
{
	btQuaternion tmp(direction, angle);
	tmp *= coords.getRotation();
	coords.setRotation(tmp);
}

void Entity::rotate(const btScalar x, const btScalar y, const btScalar z)
{
	// Order yaw, pitch, row(x, y, z)
	btQuaternion tmp(z, y, x);
	tmp *= coords.getRotation();
	coords.setRotation(tmp);
}

void Entity::resize(btScalar x, btScalar y, btScalar z)
{
	btMatrix3x3 tmp;
	tmp.setIdentity();
	tmp.scaled(btVector3(x, y, z));
	tmp *= coords.getBasis();
	coords.setBasis(tmp);
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
	btScalar *fToW = new btScalar[15];
	coords.getOpenGLMatrix(fToW);
	glMultMatrixf(reinterpret_cast<GLfloat *>(fToW));

	// Draw the entity and it's children if it isn't invisible
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

	#ifdef DRAWBOUNDINGS
	static std::list<BoundingVolume *>::iterator iter;
	
	for(iter = boundings.begin(); iter != boundings.end(); ++iter)
	{
		(*iter)->draw();
	}
	#endif

	delete fToW;
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

void Entity::setFrame(const btTransform &f){
	coords.setBasis(f.getBasis());
	coords.setOrigin(f.getOrigin());
}

const btTransform &Entity::getFrame(){
	return coords;
}

// Translate the boundings according to the entity translation
void Entity::translateBoundings()
{
	static std::list<BoundingVolume *>::iterator iter;
	
	for(iter = boundings.begin(); iter != boundings.end(); ++iter)
	{
		(*iter)->setPosition(getPosition());
		(*iter)->setChanged(true);
	}
}

// Add a bounding to the entities list
void Entity::addBoundings(BoundingVolume* bvol)
{
	boundings.push_back(bvol);
	PhysicsSystem::addVolume(bvol);
}
