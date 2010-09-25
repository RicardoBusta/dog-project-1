/*
 * ModelBullet.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "ModelBullet.h"

ModelBullet::ModelBullet() {
	// TODO Auto-generated constructor stub

}

ModelBullet::~ModelBullet() {
	// TODO Auto-generated destructor stub
}

void ModelBullet::draw(){
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
