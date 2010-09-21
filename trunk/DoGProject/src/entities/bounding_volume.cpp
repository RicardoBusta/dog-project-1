/*
 * bounding_volume.cpp
 *
 *  Created on: 21/09/2010
 *      Author: Administrador
 */

#include "bounding_volume.h"

BoundingVolume::BoundingVolume() {
	// TODO Auto-generated constructor stub

}

BoundingVolume::~BoundingVolume() {
	// TODO Auto-generated destructor stub
}

BoundingBox::BoundingBox( Point3 *position, float width, float height,  float depth)
{
	this->cur_position = position;
	this->height = height;
	this->width = width;
	this->depth = depth;

}

BoundingBox::~BoundingBox()
{
}

bool BoundingBox::checkCollision()
{
	return false;
}

void BoundingBox::setCurPosition(Point3 *position){
	this->cur_position = position;
}

float BoundingBox::getMaxX()
{
	return maxX;
}

float BoundingBox::getMaxY()
{
	return maxY;
}

float BoundingBox::getMaxZ()
{
	return maxZ;
}

void BoundingBox::drawFaces(int index, float x, float y, float z,float halfwidth, float halfheight, float halfdepth)
{
	switch (index){
		//BACK
		case 1:
			glVertex3f(x-halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z-halfdepth);
			glVertex3f(x-halfwidth,y+halfheight,z-halfdepth);
		break;
		//FRONT
		case 2:
			glVertex3f(x-halfwidth,y-halfheight,z+halfdepth);
			glVertex3f(x+halfwidth,y-halfheight,z+halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z+halfdepth);
			glVertex3f(x-halfwidth,y+halfheight,z+halfdepth);
		break;
		//LEFT
		case 3:
			glVertex3f(x-halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x-halfwidth,y+halfheight,z-halfdepth);
			glVertex3f(x-halfwidth,y+halfheight,z+halfdepth);
			glVertex3f(x-halfwidth,y-halfheight,z+halfdepth);
		break;
		//RIGHT
		case 4:
			glVertex3f(x+halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z+halfdepth);
			glVertex3f(x+halfwidth,y-halfheight,z+halfdepth);
		break;
		//TOP
		case 5:
			glVertex3f(x-halfwidth,y+halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y+halfheight,z+halfdepth);
			glVertex3f(x-halfwidth,y+halfheight,z+halfdepth);
		break;
		//BOTTOM
		case 6:
			glVertex3f(x-halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y-halfheight,z-halfdepth);
			glVertex3f(x+halfwidth,y-halfheight,z+halfdepth);
			glVertex3f(x-halfwidth,y-halfheight,z+halfdepth);
		break;
	}
}

void BoundingBox::draw()
{
	float x, y, z, halfwidth, halfheight, halfdepth;
	x = this->cur_position->getX();
	y = this->cur_position->getY();
	z = this->cur_position->getZ();
	halfwidth = width /2;
	halfheight = height/2;
	halfdepth = depth/2;
	glDisable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glDisable(GL_TEXTURE_2D);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
			for(int i = 1; i<7; i++)
			{
				drawFaces(i,x,y,z,halfwidth,halfheight,halfdepth);
			}
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(0.0,0.0,0.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);

}
