/*
 * content.cpp
 *
 *  Created on: Sep 3, 2010
 *      Author: Cleóbulo
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
    norma = sqrt( produtoEscalar( (*this) , (*this) ) );
}

void Vector3::setUnitary()
{
    if( norma != 0){
        this->x = this->x/norma;
        this->y = this->y/norma;
        this->z = this->z/norma;
    }else{
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    this->norma = 0;
}

long double Vector3::getNorma()
{
    return this->norma;
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

Vector3 Vector3::getInverso()
{
    Vector3 temp;
    temp.setVector3( -this->x , -this->y , -this->z );
    return temp;
}

Vector3 Vector3::operator+  ( Vector3 b )
{
    Vector3 temp;
    temp.setVector3( x + b.getX() , y + b.getY() , z + b.getZ() );
    return temp;
}

Vector3 Vector3::operator-  ( Vector3 b )
{
    Vector3 temp;
    temp.setVector3( x - b.getX() , y - b.getY() , z - b.getZ() );
    return temp;
}

Vector3 Vector3::operator*  ( long double Numero )
{
    Vector3 temp;
    temp.setVector3(Numero*this->x , Numero*this->y , Numero*this->z );
    return temp;
}

Vector3 Vector3::operator+= ( Vector3 b )
{
    this->setVector3( x + b.getX() , y + b.getY() , z + b.getZ() );
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
