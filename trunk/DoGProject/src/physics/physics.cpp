#include "../physics/physics.h"
#include "../entities/entity.h"
	
// Deve ser substituido por uma estrutura de particionamento de espaço: kdtree etc
std::list<BoundingVolume *> PhysicsSystem::world;		
std::list<BoundingVolume*>::iterator PhysicsSystem::iter;
std::list<BoundingVolume*>::iterator PhysicsSystem::aux;

void PhysicsSystem::addVolume(BoundingVolume * volume)
{
	world.push_back(volume);
}

void PhysicsSystem::deleteVolume(BoundingVolume *volAddress)	// Gambiarrenta... >_>
{
	world.remove(volAddress);
	delete volAddress;
}

void PhysicsSystem::processPhysics()				// Handle collision test in all the modified entities
{
	BoundingBox *bound;
	for(iter = world.begin(); iter != world.end(); ++iter)
	{
		bound = reinterpret_cast<BoundingBox *>(*iter);		// Só para o desenho
		bound->setCollide(false);							// Só para o desenho
		
		if((*iter)->getChanged())			// Realizar uma verificação mais inteligente...
		{
			for(aux = world.begin(); aux != world.end(); ++aux)
			{
				if((*iter) == (*aux))								// Wont verify a box with itself
					continue;
				intersect(*(*iter), *(*aux));				// Updates the intersection
			}
			//(*iter)->setChanged(false);					// TORNA A COLISAO MAIS EFICIENTE 
		}	
	}
}
	
void PhysicsSystem::intersect(BoundingVolume &box1, BoundingVolume &box2)
{
	BOUNDTYPE aType = box1.getType();
	BOUNDTYPE bType = box2.getType();
	if(aType == ABB && bType == ABB)			// Two ABBs test - Feito pelo Vitor
	{
		if(aabAab(box1, box2))
		{
			// Informs the two boxes about the collision, in fact, we could inform directly their entities...
			box1.collided(box2);			
			box2.collided(box1);
		}
	}
}

// Feito pelo Vitor
// Collision between two axis-aligned bounding boxes
bool PhysicsSystem::aabAab(BoundingVolume &box1, BoundingVolume &box2)
{
	// Os owners de cada box devem ser informados da colisao...
	BoundingBox *b1 = reinterpret_cast<BoundingBox *>(&box1) ;
	BoundingBox *b2 = reinterpret_cast<BoundingBox *>(&box2);
	
	b1->updateBoundaries();
	b2->updateBoundaries();
	Point3 other_max;
	Point3 other_min;
	Point3 first_max;
	Point3 first_min;
	
	
	other_max = b2->getMax();
	other_min = b2->getMin();
	first_max = b1->getMax();
	first_min = b1->getMin();

	if(first_min.x>other_max.x)
		return false;
	if(first_max.x<other_min.x)
		return false;
	if(first_min.y>other_max.y)
		return false;
	if(first_max.y<other_min.y)
		return false;
	if(first_min.z>other_max.z)
		return false;
	if(first_max.z<other_min.z)
		return false;
	return true;	
}