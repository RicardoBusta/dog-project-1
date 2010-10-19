#include "abb.h"

#include "../base/SDL.h"

BoundingBox::BoundingBox(const btVector3 &position, btScalar width, btScalar height,  btScalar depth, Entity & owner)
		: BoundingVolume(owner, ABB), pos(position.x(), position.y(), position.z())
{

	this->height = height;
	this->width = width;
	this->depth = depth;

	max.setX(pos.x()+width/2);
	max.setY(pos.y()+height/2);
	max.setZ(pos.z()+depth/2);

	min.setX(pos.x()-width/2);
	min.setY(pos.y()-height/2);
	min.setZ(pos.z()-depth/2);

	colliding = false;
}

BoundingBox::BoundingBox( btScalar x, btScalar y, btScalar z, btScalar width, btScalar height,  btScalar depth, Entity & owner)
		: BoundingVolume(owner, ABB), pos(x, y, z)
{
	this->height = height;
	this->width = width;
	this->depth = depth;

	max.setX(x+width/2);
	max.setY(y+height/2);
	max.setZ(z+depth/2);

	min.setX(x-width/2);
	min.setY(y-height/2);
	min.setZ(z-depth/2);

	colliding = false;
}

BoundingBox::~BoundingBox()
{
}

void BoundingBox::updateBoundaries()
{
	btScalar x,y, z;
	x = pos.x();
	y = pos.y();
	z = pos.z();

	max.setX(x+width/2);
	max.setY(y+height/2);
	max.setZ(z+depth/2);

	min.setX(x-width/2);
	min.setY(y-height/2);
	min.setZ(z-depth/2);
}

void BoundingBox::setPosition(const btVector3 &displacement){
	pos.setValue(displacement.x(), displacement.y(), displacement.z());
}

const btVector3 & BoundingBox::getMax() const
{
	return max;
}

const btVector3 & BoundingBox::getMin() const
{
	return min;
}

void BoundingBox::drawFaces(int index, btScalar x, btScalar y, btScalar z,btScalar halfwidth, btScalar halfheight, btScalar halfdepth) const
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
	btScalar x, y, z, halfwidth, halfheight, halfdepth;
	x = this->pos.x();
	y = this->pos.y();
	z = this->pos.z();
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
