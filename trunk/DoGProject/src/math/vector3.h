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
    Vector3( long double , long double , long double );

    // Setters
    void setX( long double );
    void setY( long double );
    void setZ( long double );
    void setVector3( long double , long double , long double );
    void setUnitary();

    // Getters
    long double getLength();
    long double getX();
    long double getY();
    long double getZ();

    // Get the symmetric vector
    Vector3 getInverse();

    // Operators overload
    Vector3 operator=  	( Vector3 );
    Vector3 operator+  	( Vector3 );
    Vector3 operator+= 	( Vector3 );
    Vector3 operator- 	( Vector3 );
    Vector3 operator-=	( Vector3 );
    Vector3 operator* 	( long double  );
    Vector3 operator*=	( long double  );
    float   operator*	( Point3 ); //dotProduct
    Vector3 operator^	( Vector3 ); //crossProduct
private:
    // Main properties
    long double length;

};

#endif // VECTOR_H
