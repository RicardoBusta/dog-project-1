/*
 * Keyboard.cpp
 *
 *  Created on: 25/09/2010
 *      Author: ricardo
 */

#include "Keyboard.h"

Keyboard::Keyboard() {
	reset();
}

Keyboard::~Keyboard() {
	// TODO Auto-generated destructor stub
}

bool Keyboard::down(){
	return down_;
}

bool Keyboard::hit(){
	return hit_;
}

bool Keyboard::release(){
	return release_;
}

void Keyboard::reset(){
	hit_ = release_ = false;
}
