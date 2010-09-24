/*
 * ModelBox.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */



#include "ModelBox.h"

ModelBox::ModelBox() {
	for( int i = 0 ; i < 8 ; i++ ){
		vr[i] = 1;
		vg[i] = 1;
		vb[i] = 1;
	}

	setData(80,10,300);
	//randomColors();
}

ModelBox::~ModelBox() {
	// TODO Auto-generated destructor stub
}

void ModelBox::draw()
{
	//std::string a("stars");
	std::string a("madeira");
	Texture *tex = ContentManager::getTexture(a);
	if(tex == NULL)
	{
		printf("Textura com erro.\n");
	}
	else
		tex->bind();

	glBegin( GL_QUADS );
		drawFace(0,1,2,3);
		drawFace(4,7,6,5);
		drawFace(2,1,5,6);
		drawFace(0,3,7,4);
		drawFace(7,3,2,6);
		drawFace(0,4,5,1);
	glEnd();
}

void ModelBox::setData( float width , float height , float depth )
{
	this->width  = width;
	this->height = height;
	this->depth  = depth;

	// Set the vertex positions
	vertex[0].setXYZ( -width/2.0f , -height/2.0f ,  depth/2.0f );
	vertex[1].setXYZ(  width/2.0f , -height/2.0f ,  depth/2.0f );
	vertex[2].setXYZ(  width/2.0f ,  height/2.0f ,  depth/2.0f );
	vertex[3].setXYZ( -width/2.0f ,  height/2.0f ,  depth/2.0f );

	vertex[4].setXYZ( -width/2.0f , -height/2.0f , -depth/2.0f );
	vertex[5].setXYZ(  width/2.0f , -height/2.0f , -depth/2.0f );
	vertex[6].setXYZ(  width/2.0f ,  height/2.0f , -depth/2.0f );
	vertex[7].setXYZ( -width/2.0f ,  height/2.0f , -depth/2.0f );
}

void ModelBox::drawFace( int a , int b , int c , int d )
{
	glTexCoord2d(0.0, 0.0);
	glColor3f( vr[a] , vg[a] , vb[a] );
	glVertex3f( vertex[a].getX() ,  vertex[a].getY() ,  vertex[a].getZ() );

	glTexCoord2d(1.0,0.0);
	glColor3f( vr[b] , vg[b] , vb[b] );
	glVertex3f( vertex[b].getX() ,  vertex[b].getY() ,  vertex[b].getZ() );

	glTexCoord2d(1.0,1.0);
	glColor3f( vr[c] , vg[c] , vb[c] );
	glVertex3f( vertex[c].getX() ,  vertex[c].getY() ,  vertex[c].getZ() );

	glTexCoord2d(0.0,1.0);
	glColor3f( vr[d] , vg[d] , vb[d] );
	glVertex3f( vertex[d].getX() ,  vertex[d].getY() ,  vertex[d].getZ() );

}


void ModelBox::randomColors()
{void setData( float width , float height , float depth );
	// Select random colors for all the vertices
	for( int i = 0 ; i < 8 ; i++ ){
		vr[i] = ((float)(rand()%101))/100.0;
		vg[i] = ((float)(rand()%101))/100.0;
		vb[i] = ((float)(rand()%101))/100.0;
	}
}
