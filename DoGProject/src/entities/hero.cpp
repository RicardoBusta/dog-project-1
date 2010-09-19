/*
 * hero.cpp
 *
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#include "hero.h"

Hero::Hero(Entity* p):Entity(p) {
	shootCoolDown = 0;
}

Hero::~Hero() {
}

void Hero::addAction( ControllerStatus control ){

}

void Hero::handleSelf()
{
	if(shootCoolDown>=0)
		shootCoolDown--;
}

void Hero::triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	glVertex3f(x1,y1,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x3,y3,z3);
}

void Hero::draw()
{
	// The entity color
	glColor3f( this->color.r , this->color.g , this->color.b );

	//sca 5 5 5
	//cen 0 0 0.7
	glScalef(50,50,50);

	glBegin(GL_TRIANGLES);
		//BRIDGE
		glColor3f(0,0.7,1);
		triangle( 0, 0, 0, -0.25, 0, 1, 0, 0.25, 1 );
		triangle( 0, 0, 0, 0, 0.25, 1, 0.25, 0, 1 );

		//ENGINE
		glColor3f(1,0.3,0);
		triangle( 0, 0.25, 1, -0.25, 0, 1, 0.25, 0, 1 );

		//WINGS
		glColor3f(0.8,0.8,0.8);
		triangle( 0, 0, 0.5, -0.75, 0, 1, 0.75, 0, 1 );
		triangle( 0, 0, 0.5, 0.75, 0, 1, -0.75, 0, 1 );
		triangle( 0, 0, 0, 0.25, 0, 1, -0.25, 0, 1 );
	glEnd();
/*
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
	glEnd();*/
}
