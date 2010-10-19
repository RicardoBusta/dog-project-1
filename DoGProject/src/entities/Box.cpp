/*
 * box.cpp
 *
 *  Created on: 14/09/2010
 *      Author: Cle�bulo
 */

// PRA TESTAR TEXTURAS - REMOVER DEPOIS - SE BEM QUE ESSE BOX EH SOH PRA TESTES MESMO
#include "../base/SDL.h"
#include "../entities/Box.h"


Box::Box(Entity* p):Entity(p) {

}

Box::~Box()
{
}

void Box::handler()
{
	this->move( btVector3(0,0,20) );
	if( coords.getOrigin().getZ() >= 600){
		this->setPosition(btVector3(coords.getOrigin().getX(),coords.getOrigin().getY(),-1200) );
	}
}
