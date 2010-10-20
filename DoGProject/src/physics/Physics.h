// Projetar aqui uma interface pra boundbox e obb, comum entre elas

#ifndef PHYSICS_H_
#define PHYSICS_H_

// Um sistema de física que gerencia apenas bound boxes, por enquanto
#include "abb.h"
//#include "obb.h"
#include <list>

class PhysicsSystem{
public:
	static void addVolume(BoundingVolume *);
	static void deleteVolume(BoundingVolume *);	// Gambiarrenta? >_>
	static void processPhysics();				// Handle collision test in all the modified entities
		// Just verifies the type of the parameters and calls the specific physics collision test
	static void intersect(BoundingVolume &, BoundingVolume &);
	static bool aabAab(BoundingVolume &, BoundingVolume &);
	
private:
	static std::list<BoundingVolume*> world; 	// Implementar uma estrutura de divisão espacial para acelerar a colisao
	static std::list<BoundingVolume*>::iterator iter;
	static std::list<BoundingVolume*>::iterator aux;
};

#endif