/*
 * ModelWeapon.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "ModelWeapon.h"
#include "../base/util.h"
#include <cmath>
ModelWeapon::ModelWeapon() {
	r = 5;
	l = 10;
}

ModelWeapon::~ModelWeapon() {
	// TODO Auto-generated destructor stub
}

void ModelWeapon::middleTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	glColor3f(1,1,1);

	glTexCoord2d(1,0.5);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0.5,0.5);
	glVertex3f(x3,y3,z3);
}

void ModelWeapon::borderTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	glColor3f(1,1,1);

	glTexCoord2d(0.5,0.5);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0.5);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0.5,1);
	glVertex3f(x3,y3,z3);
}

void ModelWeapon::draw(){
	std::string a;
	if(skin==0){
		a = "nave";
	}else{
		a = "enemy";
	}
		Texture *tex = (Texture *) ContentManager::getContent(CONTENT_TEXTURE, a);
		if(tex == NULL)
		{
			printf("Textura com erro.\n");
		}
		tex->bind();

		glPushMatrix();
		glBegin(GL_TRIANGLES);
		for(float a=0;a<360;a+=36){
			float a1 = rad(a);
			float a2 = rad(a + 36);
			borderTriangle(	0,0,0,
							r*cos(a2),r*sin(a2),0,
							r*cos(a1),r*sin(a1),0
					);
			borderTriangle(	0,0,l,
							r*cos(a1),r*sin(a1),l,
							r*cos(a2),r*sin(a2),l
					);
			middleTriangle(	r*cos(a1),r*sin(a1),0,
							r*cos(a2),r*sin(a2),0,
							r*cos(a2),r*sin(a2),l
			);
			middleTriangle(	r*cos(a2),r*sin(a2),l,
							r*cos(a1),r*sin(a1),l,
							r*cos(a1),r*sin(a1),0
			);
		}
		glEnd();
		glPopMatrix();
}
