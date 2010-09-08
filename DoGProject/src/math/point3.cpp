/*
 * point3.cpp
 *
 *  Created on: Sep 8, 2010
 *      Author: Cleóbulo
 */
#include "point3.h"
#include "vector3.h"
#include "operations.h"

Point3::Point3()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
}

Point3::Point3( long double x , long double y , long double z )
{
    setPosition( x , y , z );
}

Point3 Point3::operator*( long double escalar )
{
    Point3 temp;
    temp.setX( x * escalar );
    temp.setY( y * escalar );
    temp.setZ( z * escalar );
    return temp;
}

Point3 Point3::operator*=( long double escalar )
{
    x = x * escalar;
    y = y * escalar;
    z = z * escalar;
    return *this;
}

Point3 Point3::operator+( Point3 ponto )
{
    Point3 temp;
    temp.setX( this->x + ponto.getX() );
    temp.setY( this->y + ponto.getY() );
    temp.setZ( this->z + ponto.getZ() );
    return temp;
}

Vector3 Point3::operator- ( Point3 ponto )
{
    Vector3 temp;
    temp.setVector3( this->x - ponto.getX() , this->y - ponto.getY() , this->z - ponto.getZ() );
    return temp;
}

Point3 Point3::operator+ ( Vector3 vetor )
{
    Point3 temp;
    temp.setX( vetor.getX() + this->x );
    temp.setY( vetor.getY() + this->y );
    temp.setZ( vetor.getZ() + this->z );
    return temp;
}

Point3 Point3::operator- ( Vector3 vetor )
{
    Point3 temp;
    vetor = vetor.getInverso();
    temp.setX( vetor.getX() + this->x );
    temp.setY( vetor.getY() + this->y );
    temp.setZ( vetor.getZ() + this->z );
    return temp;
}

bool Point3::operator== ( Point3 ponto ){

    if( this->getX() == ponto.getX() and
        this->getY() == ponto.getY() and
        this->getZ() == ponto.getZ() )
        return true;

    return false;
}

long double Point3::getX()
{
    return this->x;
}

long double Point3::getY()
{
    return this->y;
}

long double Point3::getZ()
{
    return this->z;
}

void Point3::setX( long double x )
{
    this->x = x;
}

void Point3::setY( long double y )
{
    this->y = y;
}

void Point3::setZ( long double z )
{
    this->z = z;
}

void Point3::setPosition( long double x , long double y , long double z )
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Point3::setPosition( Point3 coords )
{
    this->x = coords.getX();
    this->y = coords.getY();
    this->z = coords.getZ();
}
