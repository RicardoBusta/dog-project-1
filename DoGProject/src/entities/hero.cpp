/*
 * hero.cpp
 *
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#include "hero.h"
#include "../contents/contentmanager.h"

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
	glTexCoord2d(0.5,0);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(0.5,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x3,y3,z3);
}

void Hero::draw()
{
	glColor3f(color.r,color.g,color.b);
	std::string a("nave");
	Texture *tex = (Texture *) ContentManager::getContent(CONTENT_TEXTURE, a);
	if(tex == NULL)
	{
		printf("Textura com erro.\n");
	}
	glBindTexture(GL_TEXTURE_2D, tex->getHandle());

	//sca 5 5 5
	//cen 0 0 0.7
	glPushMatrix();
	glScalef(80,80,80);

	glBegin(GL_TRIANGLES);
		//BRIDGE
			//side 1
			glTexCoord2d(0,1);
			glVertex3f(0, 0, 0);
			glTexCoord2d(0,0);
			glVertex3f(-0.25, 0, 1);
			glTexCoord2d(0.5,0);
			glVertex3f(0, 0.25, 1);
			//side 2
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0,0);
			glVertex3f( 0.25, 0, 1 );

		//ENGINE
			glTexCoord2d(1,1);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( -0.25, 0, 1 );
			glTexCoord2d(1,0.5);
			glVertex3f( 0.25, 0, 1 );

		//WINGS
		//upside
			//left
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,0);
			glVertex3f( -0.75, 0, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			//right
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0.75, 0, 1 );
		//downside
			triangle( 0, 0, 0.5, 0.75, 0, 1, -0.75, 0, 1 );
			triangle( 0, 0, 0, 0.25, 0, 1, -0.25, 0, 1 );
	glEnd();
	glPopMatrix();
}
