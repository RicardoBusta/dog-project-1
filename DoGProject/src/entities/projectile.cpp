/*
 * projectile.cpp
 *
 *  Created on: 16/09/2010
 *      Author: ricardo
 */

#include "projectile.h"

Projectile::Projectile(Vector3 d, Entity* p):Particle(p) {
	// TODO Auto-generated constructor stub
	direction = new Vector3;
	*direction = d;
	lifeTime = 25;
}

Projectile::~Projectile() {
	// TODO Auto-generated destructor stub
}

void Projectile::draw(){
	glScalef(0.2,0.2,0.2);
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

void Projectile::handleSelf(){
	this->move(*direction);
	lifeTime--;
	if(lifeTime<=0){
		toggleLive();
	}
}
