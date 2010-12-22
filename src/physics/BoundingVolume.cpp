/*
 * bounding_volume.cpp
 *
 *  Created on: 21/09/2010
 *      Author: Administrador
 */

#include "../base/SDL.h"

#include "../physics/BoundingVolume.h"

#include "../physics/abb.h"			// REMOVER DEPOIS coloquei soh pra testar uma gambiarra

#include "../entities/Entity.h"

// Bound constructor
// receives the owner, the type of volume and a callback in the owner to be called 
// at the end of collision test
BoundingVolume::BoundingVolume(Entity & owner, BOUNDTYPE type)
		: owner(owner), type(type), changed(true)		// When its created, it need to be handled by physics
{
}
	
BoundingVolume::~BoundingVolume()
{
}
	
// Returns the type of the bounding
BOUNDTYPE BoundingVolume::getType() const
{
	return type;
}

// Set changed to the parameter passed, if changed = true, the physicssystem will verify
void BoundingVolume::setChanged(bool changed)
{
	this->changed = changed;
}
	
bool BoundingVolume::getChanged() const
{
	return changed;
}
	
void BoundingVolume::collided(BoundingVolume const &vol2)
{
	// Send a signal with the appropriate parameřter...
	// OWNDER.handleColission(PARAM);			// NÃO EXISTE
	// Gambiarra aqui							// QUANDO TIVER MAIS BOUNDINGS TYPES, MELHOR UM SWITCH ETC
	if(getType() == ABB)
	{
		BoundingBox *box = reinterpret_cast<BoundingBox *>(this);
		box->setCollide(true);
	}
}
	
Entity & BoundingVolume::getOwner()
{
	return owner;
}
