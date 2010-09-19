/*
 * point3.h
 *	Abstraction of a 3D point, very simple
 *  Created on: Sep 8, 2010
 *      Author: Cle�bulo
 */
#ifndef POINT3_H
#define POINT3_H

class Vector3;

class Point3
{
    protected:
        float x,y,z;

    public:
        Point3();
        Point3( float x , float y , float z );

        //Operations with numbers
        Point3 operator+ ( float ); //Add number
        Point3 operator* ( float ); //Product with number
        Point3 operator/ ( float );	//Division by a number
        Point3 operator*=( float );
        Point3 operator/=( float );

        //Operations with points
        Point3  operator+ ( Point3 ); //Add points
        Vector3 operator- ( Point3 ); //Subtract points

        //Operations with vectors
        Point3 operator+ ( Vector3 ); //Add point with vector
        Point3 operator- ( Vector3 ); //Subtract point with vector

        //Compare
        bool operator==   ( Point3 );

        float getX();
        float getY();
        float getZ();

        // Entrada de dados
        void setX( float x );
        void setY( float y );
        void setZ( float z );
        void setXYZ( float x , float y , float z );
        void setXYZ( Point3 );
};

#endif // POINT3_H
