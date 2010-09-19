/*
 * frame.cpp
 *	The implementation of frame operations
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
 */
#include "frame.h"

Frame::Frame()
{
	//The default values
    origin.setXYZ( 0.0 , 0.0 , 0.0 );
    i.setVector3( 1.0 , 0.0 , 0.0 );
    j.setVector3( 0.0 , 1.0 , 0.0 );
    k.setVector3( 0.0 , 0.0 , 1.0 );
    angleX = angleY = angleZ = 0;
}

Frame::Frame( Point3 no , Vector3 ni , Vector3 nj , Vector3 nk )
{
	//The non-default initializer
    this->origin = no;
    this->i = ni;
    this->j = nj;
    this->k = nk;
}

void Frame::setI( Vector3 ni )
{
    this->i = ni;
}

void Frame::setJ( Vector3 nj )
{
    this->j = nj;
}

void Frame::setK( Vector3 nk )
{
    this->k = nk;
}

Vector3* Frame::getI()
{
    return &i;
}

Vector3* Frame::getJ()
{
    return &j;
}

Vector3* Frame::getK()
{
    return &k;
}

Point3* Frame::getOrigin()
{
    return &origin;
}

Vector3 Frame::convertV( Vector3 old , GLfloat* matrix )
{
	//Applies a matrix to a vector3
    Vector3 temp;
    temp.setVector3( old.getX()*matrix[0] + old.getY()*matrix[4] + old.getZ()*matrix[8] ,
                      old.getX()*matrix[1] + old.getY()*matrix[5] + old.getZ()*matrix[9] ,
                      old.getX()*matrix[2] + old.getY()*matrix[6] + old.getZ()*matrix[10] );
    return temp;
}

Point3 Frame::convertP( Point3 old , GLfloat* matrix )
{
	//Applies a matrix to a point3
    Point3 temp;
    temp.setXYZ( old.getX()*matrix[0] + old.getY()*matrix[4] + old.getZ()*matrix[8] ,
                      old.getX()*matrix[1] + old.getY()*matrix[5] + old.getZ()*matrix[9] ,
                      old.getX()*matrix[2] + old.getY()*matrix[6] + old.getZ()*matrix[10] );
    return temp;
}

void Frame::calculateRotation()
{
	// #-------------------------------------------------------------------------------------#
	//This must be redone
    GLfloat aux[16];
    glMatrixMode(GL_MODELVIEW_MATRIX);

    glPushMatrix();
    glLoadIdentity();

    glRotatef( angleX/16.0 , 1.0 , 0.0 , 0.0 );
    glRotatef( angleY/16.0 , 0.0 , 1.0 , 0.0 );
    glRotatef( angleZ/16.0 , 0.0 , 0.0 , 1.0 );

    //Obtain the rotation matrix
    glGetFloatv( GL_MODELVIEW_MATRIX, aux );

    Vector3 temp;

    temp.setVector3( 1 , 0 , 0 );
    i = convertV( temp , aux );

    temp.setVector3( 0 , 1 , 0 );
    j = convertV( temp , aux );

    temp.setVector3( 0 , 0 , 1 );
    k = convertV( temp , aux );

    glPopMatrix();
}

GLfloat* Frame::getMatrixToWorld()
{
	//Prepare the matrix to convert to world
    calculateRotation();


    //Unchanged matrix elements
    matrix[3] = matrix[7] = matrix[11] = 0;
    matrix[15] = 1;

    matrix[0]  = i.getX();
    matrix[4]  = j.getX();
    matrix[8]  = k.getX();
    matrix[12] = origin.getX();

    matrix[1]  = i.getY();
    matrix[5]  = j.getY();
    matrix[9]  = k.getY();
    matrix[13] = origin.getY();

    matrix[2]  = i.getZ();
    matrix[6]  = j.getZ();
    matrix[10] = k.getZ();
    matrix[14] = origin.getZ();

    return matrix;
}

GLfloat* Frame::getMatrixToThis()
{
    calculateRotation();

    // Unchanged matrix elements
    matrix[3] = matrix[7] = matrix[11] = 0;
    matrix[15] = 1;

    matrix[0]  = i.getX();
    matrix[4]  = i.getY();
    matrix[8]  = i.getZ();
    matrix[12] = - ( i * origin );

    matrix[1]  = j.getX();
    matrix[5]  = j.getY();
    matrix[9]  = j.getZ();
    matrix[13] = - ( j * origin );

    matrix[2]  = k.getX();
    matrix[6]  = k.getY();
    matrix[10] = k.getZ();
    matrix[14] = - ( k * origin );

    return matrix;

}

void Frame::moveOriginW( Vector3 delta )
{
    this->origin = origin + delta;
}

void Frame::moveOriginW( float dx , float dy , float dz )
{
    this->origin.setXYZ( this->origin.getX() + dx ,
                              this->origin.getY() + dy ,
                              this->origin.getZ() + dz );
}

void Frame::moveOriginT( Vector3 delta )
{
    Vector3 temp = convertV( delta , this->getMatrixToWorld()  );
    this->origin = origin + temp;
}

void Frame::moveOriginT( float dx , float dy , float dz )
{
    Vector3 temp;
    temp.setVector3( dx , dy , dz );
    moveOriginT( temp );
}

void Frame::setRotationX( int angle )
{
    this->angleX += angle;
    normalizeAngle( &this->angleX );
}

void Frame::setRotationY( int angle )
{
    this->angleY += angle;
    normalizeAngle( &this->angleY );
}

void Frame::setRotationZ( int angle )
{
    this->angleZ += angle;
    normalizeAngle( &this->angleZ );
}

void Frame::normalizeAngle(int *angle)
{
    while (*angle < 0)
    {
        *angle += 360 * 16;
    }
    while (*angle > 360 * 16)
    {
        *angle -= 360 * 16;
    }
}

void Frame::resetRotation()
{
    angleX = 0;
    angleY = 0;
    angleZ = 0;
}

int Frame::getRotationX()
{
	return angleX;
}

int Frame::getRotationY()
{
	return angleY;
}

int Frame::getRotationZ()
{
	return angleZ;
}
