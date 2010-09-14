/*
 * hero.cpp
 *
 *  Created on: 13/09/2010
 *      Author: Cleóbulo
 */

#include "hero.h"

Hero::Hero() {
}

Hero::~Hero() {
}

void Hero::addAction( ControllerStatus control ){

}

void Hero::selfHandler()
{

}

void Hero::draw()
{

	// The entity color
	glColor3f( this->color.r , this->color.g , this->color.b );

	// Pyramid like
	glBegin( GL_TRIANGLE_FAN );
		glVertex3f( coords.getOrigin()->getX() ,
					coords.getOrigin()->getY() ,
					coords.getOrigin()->getZ() - 25.0f );
		glVertex3f( coords.getOrigin()->getX() -25.0f,
					coords.getOrigin()->getY() +25.0f,
					coords.getOrigin()->getZ() +25.0f);
		glVertex3f( coords.getOrigin()->getX() +25.0f,
					coords.getOrigin()->getY() +25.0f,
					coords.getOrigin()->getZ() +25.0f);
		glVertex3f( coords.getOrigin()->getX() +25.0f,
					coords.getOrigin()->getY() -25.0f,
					coords.getOrigin()->getZ() +25.0f);
		glVertex3f( coords.getOrigin()->getX() -25.0f,
					coords.getOrigin()->getY() -25.0f,
					coords.getOrigin()->getZ() +25.0f);
	glEnd();

	// The bottom of the pyramid
	glBegin( GL_QUADS );
	glVertex3f( coords.getOrigin()->getX() -25.0f,
				coords.getOrigin()->getY() -25.0f,
				coords.getOrigin()->getZ() +25.0f);
	glVertex3f( coords.getOrigin()->getX() +25.0f,
				coords.getOrigin()->getY() -25.0f,
				coords.getOrigin()->getZ() +25.0f);
	glVertex3f( coords.getOrigin()->getX() +25.0f,
				coords.getOrigin()->getY() +25.0f,
				coords.getOrigin()->getZ() +25.0f);
	glVertex3f( coords.getOrigin()->getX() -25.0f,
				coords.getOrigin()->getY() +25.0f,
				coords.getOrigin()->getZ() +25.0f);
	glEnd();
}
