/*
 * box.cpp
 *
 *  Created on: 14/09/2010
 *      Author: Cle�bulo
 */

#include "box.h"

Box::Box() {
}

Box::~Box() {
}

void Box::randomColors()
{
	// Select random colors for all the vertices
	for( int i = 0 ; i < 8 ; i++ ){
		vr[i] = ((float)(rand()%101))/100.0;
		vg[i] = ((float)(rand()%101))/100.0;
		vb[i] = ((float)(rand()%101))/100.0;
	}
}

void Box::setData( float width , float height , float depth )
{
	this->width  = width;
	this->height = height;
	this->depth  = depth;

	// Set the vertex positions
	vertex[0].setPosition( -width/2.0f , -height/2.0f ,  depth/2.0f );
	vertex[1].setPosition(  width/2.0f , -height/2.0f ,  depth/2.0f );
	vertex[2].setPosition(  width/2.0f ,  height/2.0f ,  depth/2.0f );
	vertex[3].setPosition( -width/2.0f ,  height/2.0f ,  depth/2.0f );

	vertex[4].setPosition( -width/2.0f , -height/2.0f , -depth/2.0f );
	vertex[5].setPosition(  width/2.0f , -height/2.0f , -depth/2.0f );
	vertex[6].setPosition(  width/2.0f ,  height/2.0f , -depth/2.0f );
	vertex[7].setPosition( -width/2.0f ,  height/2.0f , -depth/2.0f );
}

void Box::handleSelf()
{
	this->move( Vector3(0,0,5) );
}

void Box::drawFace( int a , int b , int c , int d ){

	glColor3f( vr[a] , vg[a] , vb[a] );
	glVertex3f( vertex[a].getX() ,  vertex[a].getY() ,  vertex[a].getZ() );
	glColor3f( vr[b] , vg[b] , vb[b] );
	glVertex3f( vertex[b].getX() ,  vertex[b].getY() ,  vertex[b].getZ() );
	glColor3f( vr[c] , vg[c] , vb[c] );
	glVertex3f( vertex[c].getX() ,  vertex[c].getY() ,  vertex[c].getZ() );
	glColor3f( vr[d] , vg[d] , vb[d] );
	glVertex3f( vertex[d].getX() ,  vertex[d].getY() ,  vertex[d].getZ() );
}

void Box::draw()
{
	glBegin( GL_QUADS );
		drawFace(0,1,2,3);
		drawFace(4,7,6,5);
		drawFace(2,1,5,6);
		drawFace(0,3,7,4);
		drawFace(7,3,2,6);
		drawFace(0,4,5,1);
	glEnd();
}
