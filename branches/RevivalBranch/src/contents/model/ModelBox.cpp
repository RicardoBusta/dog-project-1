/*
 * ModelBox.cpp
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */



#include "ModelBox.h"
//#include "../../math/Vector3.h"

ModelBox::ModelBox() {
	for( int i = 0 ; i < 8 ; i++ ){
		vr[i] = 1;
		vg[i] = 1;
		vb[i] = 1;
	}

	setData(120,10,300);
	//randomColors();
}

ModelBox::~ModelBox() {
	// TODO Auto-generated destructor stub
}

void ModelBox::draw()
{
	Texture *tex = ContentManager::getTexture(label);
	if(tex == NULL)
	{
		printf("Textura com erro.\n");
	}
	else
		tex->bind();

	glBegin( GL_QUADS );
		//drawFace(0,1,2,3); //front face
		//drawFace(4,7,6,5); //back face
		//drawFace(2,1,5,6); //right face
		//drawFace(0,3,7,4); //left face
		drawFace(7,3,2,6); // top face
		//drawFace(0,4,5,1); //bottom face
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
	Vector3 Normal;
	Normal = ( vertex[a] + vertex[b] + vertex[c] + vertex[d] );
	Normal.setUnitary();

	glNormal3f(Normal.getX(),Normal.getY(),Normal.getZ());
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

void ModelBox::setTexture(string tex)
{
	this->label=tex;
}

