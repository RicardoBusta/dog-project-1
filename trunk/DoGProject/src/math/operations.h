/*
 * operations.h
 *	The main operations manipulating points and vectors
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

// Will be envolved in this
class Point3;
class Vector3;

// Intuitive labels, anyway

// Cross-Product
Vector3 produtoVetorial( Vector3 a , Vector3 b );

// Norma
Vector3 normalize( Vector3 a );

// Dot-Product
long double produtoEscalar( Vector3 a , Vector3 b);

// Dot-Product overload
long double produtoEscalar( Vector3 a , Point3 b);

#endif /* OPERATIONS_H_ */
