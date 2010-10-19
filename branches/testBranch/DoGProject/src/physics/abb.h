#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "../physics/BoundingVolume.h" // Base class: BoundingVolume


class BoundingBox : public BoundingVolume {
		friend class Scene;
public:
	BoundingBox(const btVector3 &position, btScalar width, btScalar height,  btScalar depth, Entity & owner);
	BoundingBox( btScalar x, btScalar y, btScalar z, btScalar width, btScalar height,  btScalar depth, Entity & owner);
//	BoundingBox(Point3 *position, Point3 max, Point3 min);
//	BoundingBox(Point3 position, Point3 max, Point3 min);
	~BoundingBox();

	void draw() const;
	void drawFaces(int index, btScalar x, btScalar y, btScalar z,btScalar halfwidth, btScalar halfheight, btScalar halfdepth) const;
	void updateBoundaries();

	void setPosition(const btVector3 &displacement);

	const btVector3 & getPosition() const;

	const btVector3 & getMax() const;
	const btVector3 & getMin() const;

	void setCollide(bool a);

private:
	btVector3 pos;
	float height;
	float width;
	float depth;

	btVector3 max;
	btVector3 min;

	bool colliding;

};

/* todo class BoundingSphere : public BoundingVolume{
public:
	BoundingSphere(Point3 position, float radius);
	~BoundingSphere();
};*/

#endif // BOUNDINGBOX_H
