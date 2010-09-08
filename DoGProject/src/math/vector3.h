/*
 * vector3.h
 *	Abstraction of a 3D vector
 *  Created on: Sep 8, 2010
 *      Author: Cleóbulo
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>

class Point3;

class Vector3
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
    long double getNorma();
    long double getX();
    long double getY();
    long double getZ();

    // Get the symmetric vector
    Vector3 getInverso();

    // Operators overload
    Vector3 operator+  ( Vector3 );
    Vector3 operator+= ( Vector3 );
    Vector3 operator-  ( Vector3 );
    Vector3 operator-= ( Vector3 );
    Vector3 operator*  ( long double  );
    Vector3 operator*= ( long double  );

private:
    // Main properties
    long double x , y , z;
    long double norma;		// This way we avoid recalculating it, everytime we use it

};

#endif // VECTOR_H
