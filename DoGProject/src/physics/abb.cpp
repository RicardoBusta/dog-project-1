#include "abb.h"

#include "../base/sdl.h"

BoundingBox::BoundingBox( Point3 position, float width, float height,  float depth, Entity & owner)
		: BoundingVolume(owner, ABB)
{
	float x, y, z;
	x = position.getX();
	y = position.getY();
	z = position.getZ();

	this->cur_position = new Point3;
	*this->cur_position = position;

	this->height = height;
	this->width = width;
	this->depth = depth;

	max.x = x+width/2;
	max.y = y+height/2;
	max.z = z+depth/2;

	min.x = x-width/2;
	min.y = y-height/2;
	min.z = z-depth/2;

	colliding = false;
}

BoundingBox::BoundingBox( float x, float y, float z, float width, float height,  float depth, Entity & owner)
		: BoundingVolume(owner, ABB)
{
	cur_position = new Point3();
	cur_position->x = x;
	cur_position->y = y;
	cur_position->z = z;

	this->height = height;
	this->width = width;
	this->depth = depth;

	max.x = x+width/2;
	max.y = y+height/2;
	max.z = z+depth/2;

	min.x = x-width/2;
	min.y = y-height/2;
	min.z = z-depth/2;

	colliding = false;
}

BoundingBox::~BoundingBox()
{
}

void BoundingBox::updateBoundaries()
{
	float x,y, z;
	x = cur_position->x;
	y = cur_position->y;
	z = cur_position->z;

	max.x = x+width/2;
	max.y = y+height/2;
	max.z = z+depth/2;

	min.x = x-width/2;
	min.y = y-height/2;
	min.z = z-depth/2;
}

void BoundingBox::setPosition(Point3 const & position){
	*this->cur_position = position;
}

Point3 BoundingBox::getMax()
{
	return max;
}

Point3 BoundingBox::getMin()
{
	return min;
}

void BoundingBox::drawFaces(int index, float x, float y, float z,float halfwidth, float halfheight, float halfdepth) const
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

void BoundingBox::draw() const
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
	
	if(colliding==true)
		glColor3f(1.0,0.0,0.0);
	else
		glColor3f(0.0,0.0,1.0);
	glBegin(GL_QUADS);
			for(int i = 1; i<7; i++)
			{
				drawFaces(i,x,y,z,halfwidth,halfheight,halfdepth);
			}
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);

}

	void BoundingBox::setCollide(bool a)
	{
		colliding =  a;
	}