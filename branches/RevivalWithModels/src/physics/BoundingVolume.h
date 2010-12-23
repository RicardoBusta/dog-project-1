/*
 * bounding_volume.h
 *
 *  Created on: 21/09/2010
 *      Author: Shade
 * 	Modified on: 24/09/2010
 * 		Author: Fernando
 */

#include "../math/Point3.h"
#include "../math/Vector3.h"



#ifndef BOUNDING_VOLUME_H_
#define BOUNDING_VOLUME_H_

class Entity;

enum BOUNDTYPE {ABB, OBB, SPHERE};	// Bounding type
enum COLLISIONPARAM {ENEMYCOL};		// Can be changed to the type of the entity being collided
// Represents abstractedly a bounding volume
class BoundingVolume {
	friend class Scene;
public:
	// Bound constructor
	// receives the owner, the type of volume and a callback in the owner to be called 
	// at the end of collision test
	BoundingVolume(Entity &, BOUNDTYPE);
	virtual ~BoundingVolume();
	// Returns the type of the bounding
	BOUNDTYPE getType() const;
	// Draws the bounding volume
	virtual void draw() const = 0;
	// Sets the position or center position
	virtual void setPosition(Point3 const & pos) = 0;
	// Sends a "signal" to the owner, informing about the collision to his owner
	void setChanged(bool);
	bool getChanged() const;
	Entity& getOwner();
	void collided(BoundingVolume const &);
private:
	const BOUNDTYPE type;			// Bounding type
	Entity & owner;			// bound owner
	bool changed;			// Changed(if true, the object will be handled by the physics)
	// Maybe it's better to put this atribute as an "element" atribute in the nodes
	// of the Bounding Volume repository
};


#endif /* BOUNDING_VOLUME_H_ */
