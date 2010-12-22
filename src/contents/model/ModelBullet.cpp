/*
 * ModelBullet.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "ModelBullet.h"
#include "../../math/TriangleMath.h"

ModelBullet::ModelBullet() {
	// TODO Auto-generated constructor stub

}

ModelBullet::~ModelBullet() {
	// TODO Auto-generated destructor stub
}

void ModelBullet::triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	Vector3 Normal;

	Normal = triangleNormal(x1,y1,z1,x2,y2,z2,x3,y3,z3);
	glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());

	//glTexCoord2d(0.5,0.5);
	glVertex3f(x1,y1,z1);
	//glTexCoord2d(0.5,1);
	glVertex3f(x2,y2,z2);
	//glTexCoord2d(1,0.5);
	glVertex3f(x3,y3,z3);
}

void ModelBullet::draw(){
		//glDisable(GL_TEXTURE_2D);
		glColor3f(0,1,1);
		glBegin( GL_TRIANGLES );
			triangle(
					0,0,0,
					-20,0,-20,
					20,0,20
					);
			triangle(
					0,0,0,
					20,0,20,
					-20,0,-20
					);
			triangle(
								0,0,0,
								20,20,0,
								-20,-20,-0
								);
		glEnd();
			// The bottom of the pyramid
		//glEnable(GL_TEXTURE_2D);
}
