/*
 * ModelShip.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

#include "ModelShip.h"

#include "../../math/TriangleMath.h"

ModelShip::ModelShip() {
	// TODO Auto-generated constructor stub

}

ModelShip::~ModelShip() {
	// TODO Auto-generated destructor stub
}

void ModelShip::triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	Vector3 Normal;
	Normal = triangleNormal(x1,y1,z1,x2,y2,z2,x3,y3,z3);

	glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
	glTexCoord2d(0.5,0.5);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(0.5,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(1,0.5);
	glVertex3f(x3,y3,z3);
}

void ModelShip::draw(){
	std::string a;
	if(skin==0){
		a = "nave";
	}else{
		a = "enemy";
	}
	Texture *tex = ContentManager::getTexture(a);
	if(tex == NULL)
	{
		printf("Textura com erro.\n");
	}
	tex->bind();

	glPushMatrix();
	glScalef(80,80,80);

	Vector3 Normal;
	glBegin(GL_TRIANGLES);
		//BRIDGE
			//side 1
			Normal = triangleNormal(0,0,0,-0.25, 0, 1,0, 0.25, 1);
			glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
			glTexCoord2d(0,1);
			glVertex3f(0, 0, 0);
			glTexCoord2d(0,0);
			glVertex3f(-0.25, 0, 1);
			glTexCoord2d(0.5,0);
			glVertex3f(0, 0.25, 1);
			//side 2
			Normal = triangleNormal(0,0,0, 0, 0.25, 1 , 0.25, 0, 1 );
			glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0,0);
			glVertex3f( 0.25, 0, 1 );

		//ENGINE
			Normal = triangleNormal( 0, 0.25, 1 , -0.25, 0, 1 , 0.25, 0, 1 );
			glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
			glTexCoord2d(1,1);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( -0.25, 0, 1 );
			glTexCoord2d(1,0.5);
			glVertex3f( 0.25, 0, 1 );

		//WINGS
		//upside
			//left
			Normal = triangleNormal( 0, 0, 0.5, -0.75, 0, 1, 0, 0, 1  );
			glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,0);
			glVertex3f( -0.75, 0, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			//right
			Normal = triangleNormal( 0, 0, 0.5, 0, 0, 1, 0.75, 0, 1);
			glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0.75, 0, 1 );
		//Tail
			triangle(	0 , 0.35 , 1,
						0 , 0 , 1,
						0 , 0 , 0.3
					);
			triangle(	0 , 0.35 , 1,
						0 , 0 , 0.3,
						0 , 0 , 1
					);
		//downside
			//wings
			triangle( 	-0.15, 0, 0.6,
						-0.25, 0, 1,
						-0.75, 0, 1
					);
			triangle( 	0.15, 0, 0.6,
						0.75, 0, 1,
						0.25, 0, 1
					);
			//middle
			triangle( 	0, 0, 0,
						0.25, 0, 1,
						-0.25, 0, 1
					);
	glEnd();
	glPopMatrix();
}
