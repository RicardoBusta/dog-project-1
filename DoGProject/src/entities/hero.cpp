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
		glColor3f( 0.4 , 0.4 , 0.4 );
		glVertex3f(  0,
					 0,
					-25.0f );
		glColor3f( 0.7 , 0.7 , 0.7 );
		glVertex3f( -25.0f,
					 25.0f,
					 25.0f);
		glColor3f( 0.6 , 0.6 , 0.6 );
		glVertex3f(  25.0f,
					 25.0f,
					 25.0f);
		glColor3f( 0.5 , 0.5 , 0.5 );
		glVertex3f(  25.0f,
					-25.0f,
					 25.0f);
		glColor3f( 0.8 , 0.8 , 0.8 );
		glVertex3f( -25.0f,
					-25.0f,
					 25.0f);
		glColor3f( 0.7 , 0.7 , 0.7 );
		glVertex3f( -25.0f,
					 25.0f,
					 25.0f);
	glEnd();

	// The bottom of the pyramid
	glBegin( GL_QUADS );
		glVertex3f( -25.0f,
					-25.0f,
					 25.0f);
		glVertex3f(  25.0f,
					-25.0f,
					 25.0f);
		glVertex3f(	 25.0f,
					 25.0f,
					 25.0f);
		glVertex3f( -25.0f,
					 25.0f,
					 25.0f);
	glEnd();
}
