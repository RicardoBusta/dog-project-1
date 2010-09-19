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
	glDisable(GL_TEXTURE_2D);
	glScalef(0.2,0.2,0.2);
	glBegin( GL_TRIANGLE_FAN );
			glColor3f( 0 , 1 , 1 );
			glVertex3f(  0,
						 0,
						-25.0f );
			glVertex3f( -25.0f,
						 25.0f,
						 25.0f);
			glVertex3f(  25.0f,
						 25.0f,
						 25.0f);
			glVertex3f(  25.0f,
						-25.0f,
						 25.0f);
			glVertex3f( -25.0f,
						-25.0f,
						 25.0f);
			glVertex3f( -25.0f,
						 25.0f,
						 25.0f);
		glEnd();

		// The bottom of the pyramid
		glBegin( GL_QUADS );
			glColor3f(0,1,1);
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
		glEnable(GL_TEXTURE_2D);
}

void Projectile::handleSelf(){
	this->move(*direction);
	lifeTime--;
	if(lifeTime<=0){
		toggleLive();
	}
}
