/*
 * box.cpp
 *
 *  Created on: 14/09/2010
 *      Author: Cle�bulo
 */

// PRA TESTAR TEXTURAS - REMOVER DEPOIS - SE BEM QUE ESSE BOX EH SOH PRA TESTES MESMO
#include "../base/sdl.h"
#include "../entities/box.h"


Box::Box(Entity* p):Entity(p) {

}

Box::~Box()
{
}

void Box::handler()
{
	this->move( Vector3(0,0,10) );
	if( coords.getOrigin()->getZ() >= 600){
		this->setPosition( Point3(coords.getOrigin()->getX(),coords.getOrigin()->getY(),-600) );
	}
}
