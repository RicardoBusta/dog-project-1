/*
 * content.cpp
 *
 *  Created on: Sep 3, 2010
 *      Author: Cle�bulo
 */
#include "point3.h"
#include "vector3.h"

Vector3::Vector3()
{
}

Vector3::Vector3( float x , float y , float z )
{
    setVector3(x,y,z);
}

void Vector3::setX( float X )
{
    if( X != this->x )
        setVector3( X , this->y , this->z );
}

void Vector3::setY( float Y )
{
    if( Y != this->y )
        setVector3( this->x , Y , this->z );
}
void Vector3::setZ( float Z )
{
    if( Z != this->z )
        setVector3( this->x , this->y , Z );
}

void Vector3::setVector3( float x , float y , float z )
{
    this->x = x;
    this->y = y;
    this->z = z;
    //setLength();
}

void Vector3::setUnitary()
{
    *this /= getLength(); //set it to unitary if length is != 0, else set it to 0,0,0
}
/*
void Vector3::setLength(){
	length = sqrt( (*this)*(*this) );
}
*/
float Vector3::getLength()
{
	return sqrt( (*this)*(*this) );
	//return this->length;
}

float Vector3::getX()
{
    return this->x;
}

float Vector3::getY()
{
    return this->y;
}

float Vector3::getZ()
{
    return this->z;
}

Vector3 Vector3::getInverse()
{
    return *this*-1;
}

Vector3 Vector3::operator= 	( Point3 b ){
	this->setVector3(b.getX(), b.getY(), b.getZ());
	return *this;
}

Vector3 Vector3::operator+  ( Point3 b )
{
    Vector3 temp;
    temp.setVector3( x + b.getX() , y + b.getY() , z + b.getZ() );
    return temp;
}

Vector3 Vector3::operator-  ( Point3 b )
{
    Vector3 temp;
    temp.setVector3( x - b.getX() , y - b.getY() , z - b.getZ() );
    return temp;
}

Vector3 Vector3::operator*  ( float n )
{
    Vector3 temp;
    temp.setVector3(n*this->x , n*this->y , n*this->z );
    return temp;
}

Vector3 Vector3::operator+= ( Point3 b )
{
    this->setVector3( x + b.getX() , y + b.getY() , z + b.getZ() );
    return (*this);
}

Vector3 Vector3::operator-= ( Point3 b )
{
    this->setVector3( x - b.getX() , y - b.getY() , z - b.getZ() );
    return (*this);
}

Vector3 Vector3::operator*= ( float Numero )
{
    this->setVector3(Numero*this->x , Numero*this->y , Numero*this->z );
    return (*this);
}

float Vector3::operator* ( Point3 v ){
	return  ( this->x*v.getX()+this->y*v.getY()+this->z*v.getZ() );
}

Vector3 Vector3::operator^ ( Point3 v ){
	Vector3 temp;
	temp.setVector3(
			y*v.getZ() - z*v.getY(),
			z*v.getX() - x*v.getZ(),
			x*v.getY() - y*v.getX()
    );
	return temp;
}
