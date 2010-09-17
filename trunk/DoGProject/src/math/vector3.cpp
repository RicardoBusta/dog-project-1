/*
 * content.cpp
 *
 *  Created on: Sep 3, 2010
 *      Author: Cle�bulo
 */
#include "point3.h"
#include "vector3.h"
#include "operations.h"

Vector3::Vector3()
{
}

Vector3::Vector3( long double x , long double y , long double z )
{
    setVector3(x,y,z);
}

void Vector3::setX( long double X )
{
    if( X != this->x )
        setVector3( X , this->y , this->z );
}

void Vector3::setY( long double Y )
{
    if( Y != this->y )
        setVector3( this->x , Y , this->z );
}
void Vector3::setZ( long double Z )
{
    if( Z != this->z )
        setVector3( this->x , this->y , Z );
}

void Vector3::setVector3( long double x , long double y , long double z )
{
    this->x = x;
    this->y = y;
    this->z = z;
    length = sqrt( (*this)*(*this) );
}

void Vector3::setUnitary()
{
    if( length != 0){
        this->x = this->x/length;
        this->y = this->y/length;
        this->z = this->z/length;
    }else{
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    this->length = 0;
}

long double Vector3::getLength()
{
    return this->length;
}

long double Vector3::getX()
{
    return this->x;
}

long double Vector3::getY()
{
    return this->y;
}

long double Vector3::getZ()
{
    return this->z;
}

Vector3 Vector3::getInverse()
{
    Vector3 temp;
    temp.setVector3( -this->x , -this->y , -this->z );
    return temp;
}

Vector3 Vector3::operator= 	( Vector3 b ){
	this->x = b.x;
	this->y = b.y;
	this->z = b.z;
	this->length = b.length;
	return *this;
}

Vector3 Vector3::operator+  ( Vector3 b )
{
    Vector3 temp;
    temp.setVector3( x + b.x , y + b.y , z + b.z );
    return temp;
}

Vector3 Vector3::operator-  ( Vector3 b )
{
    Vector3 temp;
    temp.setVector3( x - b.x , y - b.y , z - b.z );
    return temp;
}

Vector3 Vector3::operator*  ( long double n )
{
    Vector3 temp;
    temp.setVector3(n*this->x , n*this->y , n*this->z );
    return temp;
}

Vector3 Vector3::operator+= ( Vector3 b )
{
    this->setVector3( x + b.x , y + b.y , z + b.z );
    return (*this);
}

Vector3 Vector3::operator-= ( Vector3 b )
{
    this->setVector3( x - b.getX() , y - b.getY() , z - b.getZ() );
    return (*this);
}

Vector3 Vector3::operator*= ( long double Numero )
{
    this->setVector3(Numero*this->x , Numero*this->y , Numero*this->z );
    return (*this);
}

float Vector3::operator* ( Point3 v ){
	return  ( this->x*v.getX()+this->y*v.getY()+this->z*v.getZ() );
}

Vector3 Vector3::operator^ ( Vector3 v ){
	Vector3 temp;
	temp.setXYZ(
			y*v.z - z*v.y,
			z*v.x - x*v.z,
			x*v.y - y*v.x
    );
	return temp;
}
