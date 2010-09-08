/*
 * operations.cpp
 *	The implementation of the operations
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
 */
#include "operations.h"
#include "point3.h"
#include "vector3.h"

Vector3 produtoVetorial( Vector3 a , Vector3 b )
{
    Vector3 temp;
    temp.setVector3((a.getY()*b.getZ()) - (a.getZ()*b.getY()),
                    (a.getZ()*b.getX()) - (a.getX()*b.getZ()),
                    (a.getX()*b.getY()) - (a.getY()*b.getX()));
    return temp;
}

Vector3 normalize( Vector3 a )
{
    Vector3 temp;
    temp.setVector3( a.getX() , a.getY() , a.getZ() );
    temp.setUnitary();
    return temp;
}

long double produtoEscalar( Vector3 a , Vector3 b )
{
    return (a.getX()*b.getX()) +
           (a.getY()*b.getY()) +
           (a.getZ()*b.getZ());
}

long double produtoEscalar( Vector3 a , Point3 b )
{
    return (a.getX()*b.getX()) +
           (a.getY()*b.getY()) +
           (a.getZ()*b.getZ());
}
