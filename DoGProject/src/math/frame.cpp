/*
 * frame.cpp
 *	The implementation of frame operations
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */
#include "frame.h"
#include "operations.h"

Frame::Frame()
{
	// The default values
    origin.setPosition( 0.0 , 0.0 , 0.0 );
    i.setVector3( 1.0 , 0.0 , 0.0 );
    j.setVector3( 0.0 , 1.0 , 0.0 );
    k.setVector3( 0.0 , 0.0 , 1.0 );
    angleX = angleY = angleZ = 0;
}

Frame::Frame( Point3 origin , Vector3 i , Vector3 j , Vector3 k )
{
	// The non-default initializer
    this->origin = origin;
    this->i = i;
    this->j = j;
    this->k = k;
}

void Frame::setI( Vector3 i )
{
    this->i = i;
}

void Frame::setJ( Vector3 )
{
    this->j = j;
}

void Frame::setK( Vector3 )
{
    this->k = k;
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
	// Applys a matrix to a vector3
    Vector3 temp;
    temp.setVector3( old.getX()*matrix[0] + old.getY()*matrix[4] + old.getZ()*matrix[8] ,
                      old.getX()*matrix[1] + old.getY()*matrix[5] + old.getZ()*matrix[9] ,
                      old.getX()*matrix[2] + old.getY()*matrix[6] + old.getZ()*matrix[10] );
    return temp;
}

Point3 Frame::convertP( Point3 old , GLfloat* matrix )
{
	// Applys a matrix to a point3
    Point3 temp;
    temp.setPosition( old.getX()*matrix[0] + old.getY()*matrix[4] + old.getZ()*matrix[8] ,
                      old.getX()*matrix[1] + old.getY()*matrix[5] + old.getZ()*matrix[9] ,
                      old.getX()*matrix[2] + old.getY()*matrix[6] + old.getZ()*matrix[10] );
    return temp;
}

void Frame::calculateRotation()
{
	// #-------------------------------------------------------------------------------------#
	// This must be redone
    GLfloat aux[16];
    glMatrixMode(GL_MODELVIEW_MATRIX);

    glPushMatrix(); // Salva matriz
    glLoadIdentity(); // Carrega identidade

    glRotatef( angleX/16.0 , 1.0 , 0.0 , 0.0 );
    glRotatef( angleY/16.0 , 0.0 , 1.0 , 0.0 );
    glRotatef( angleZ/16.0 , 0.0 , 0.0 , 1.0 );

    // Consegue a matriz de rota��o
    glGetFloatv( GL_MODELVIEW_MATRIX, aux );

    Vector3 temp;

    temp.setVector3( 1 , 0 , 0 );
    i = convertV( temp , aux );

    temp.setVector3( 0 , 1 , 0 );
    j = convertV( temp , aux );

    temp.setVector3( 0 , 0 , 1 );
    k = convertV( temp , aux );

    // Restaura matrix inicial
    glPopMatrix();
}

GLfloat* Frame::getMatrixToWorld()
{
	// Really prepare the matrix to convert to world
    calculateRotation();


    // Unchanged matrix elements
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
	// The most usual matrix is prepared
	// it bring the world to this
    calculateRotation();

    // Unchanged matrix elements
    matrix[3] = matrix[7] = matrix[11] = 0;
    matrix[15] = 1;

    matrix[0]  = i.getX();
    matrix[4]  = i.getY();
    matrix[8]  = i.getZ();
    matrix[12] = - produtoEscalar( i , origin );

    matrix[1]  = j.getX();
    matrix[5]  = j.getY();
    matrix[9]  = j.getZ();
    matrix[13] = - produtoEscalar( j , origin );

    matrix[2]  = k.getX();
    matrix[6]  = k.getY();
    matrix[10] = k.getZ();
    matrix[14] = - produtoEscalar( k , origin );

    return matrix;

}

void Frame::moveOriginW( Vector3 delta )
{
    this->origin = origin + delta;
}

void Frame::moveOriginW( float dx , float dy , float dz )
{
    this->origin.setPosition( this->origin.getX() + dx ,
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
