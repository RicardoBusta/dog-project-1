/*
 * entity.cpp
 *
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#include "entity.h"

entity::entity() {
	visible = false;
	frozen = true;
	live = true;

	setPosition(0,0,0);
	setRotation(0,0,0);
	setScale(1,1,1);
	setColor(1,1,1);
}

entity::~entity() {
	killSons();
}

void entity::drawSons(){
	list<entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		(*it)->draw();
	}
}

void entity::handleSons(){
	list<entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		(*it)->handle();
	}
}

void entity::killSons(){
//this
	list<entity*>::iterator it;
	while (!sons.empty()){
		it = sons.begin();
		delete (*it);
		sons.pop_front();
	}
//or this
	list<entity*>::iterator it;
	for(it = sons.begin(); it!=sons.end(); it++){
		delete (*it);
	}
	sons.clear();
}
