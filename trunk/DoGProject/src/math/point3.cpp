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
    setXYZ( x , y , z );
}

Point3 Point3::operator*( long double n )
{
    Point3 temp;
    temp.setX( x * n );
    temp.setY( y * n );
    temp.setZ( z * n );
    return temp;
}

Point3 Point3::operator*=( long double n )
{
    x = x * n;
    y = y * n;
    z = z * n;
    return *this;
}

Point3 Point3::operator+( Point3 ponto )
{
    Point3 temp;
    temp.setX( this->x + ponto.x );
    temp.setY( this->y + ponto.y );
    temp.setZ( this->z + ponto.z );
    return temp;
}

Vector3 Point3::operator- ( Point3 p )
{
    Vector3 temp;
    temp.setVector3( this->x - p.x , this->y - p.y , this->z - p.z );
    return temp;
}

Point3 Point3::operator+ ( Vector3 v )
{
    Point3 temp;
    temp.setX( this->x + v.getX() );
    temp.setY( v.getY() + this->y );
    temp.setZ( v.getZ() + this->z );
    return temp;
}

Point3 Point3::operator- ( Vector3 v )
{
    Point3 temp;
    temp.setX( this->x - v.x );
    temp.setY( this->y - v.y );
    temp.setZ( this->z - v.z );
    return temp;
}

bool Point3::operator== ( Point3 p ){

    if( this->x == p.x and
        this->y == p.y and
        this->z == p.z )
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

void Point3::setX( long double nx )
{
    this->x = nx;
}

void Point3::setY( long double ny )
{
    this->y = ny;
}

void Point3::setZ( long double nz )
{
    this->z = nz;
}

void Point3::setXYZ( long double nx , long double ny , long double nz )
{
    this->x = nx;
    this->y = ny;
    this->z = nz;
}

void Point3::setXYZ( Point3 p )
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}
