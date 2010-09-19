/*
 * vector3.h
 *	Abstraction of a 3D vector
 *  Created on: Sep 8, 2010
 *      Author: Cle�bulo
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>

#include "point3.h"

class Vector3:public Point3
{
public:
    Vector3();
    Vector3( float , float , float );

    // Setters
    void setX( float );
    void setY( float );
    void setZ( float );
    void setVector3( float , float , float );
    void setUnitary();
    //void setLength();

    // Getters
    float getLength();
    float getX();
    float getY();
    float getZ();

    // Get the symmetric vector
    Vector3 getInverse();

    // Operators overload
    Vector3 operator=  	( Point3 );
    Vector3 operator+  	( Point3 );
    Vector3 operator+= 	( Point3 );
    Vector3 operator- 	( Point3 );
    Vector3 operator-=	( Point3 );
    Vector3 operator* 	( float );
    Vector3 operator*=	( float );
    float   operator*	( Point3 ); //dotProduct
    Vector3 operator^	( Point3 ); //crossProduct
private:
    // Main properties
    //long double length;

};

#endif // VECTOR_H
