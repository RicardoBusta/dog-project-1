/*
 * TriangleMath.cpp
 *
 *  Created on: 05/10/2010
 *      Author: ricardo
 */

#include "TriangleMath.h"

#include "Vector3.h"
#include "Point3.h"

Vector3 triangleNormal(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	Vector3 v1, v2, Normal;
	v1 = Point3(x2,y2,z2) - Point3(x1,y1,z1);
	v2 = Point3(x3,y3,z3) - Point3(x1,y1,z1);
	Normal = v1^v2;
	Normal.setUnitary();
	return Normal;
}
