#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "../physics/BoundingVolume.h" // Base class: BoundingVolume


class BoundingBox : public BoundingVolume {
		friend class Scene;
public:
	BoundingBox(Point3 position, float width, float height, float depth, Entity & owner);
	BoundingBox(float x, float y, float z, float width, float height, float depth, Entity & owner);
//	BoundingBox(Point3 *position, Point3 max, Point3 min);
//	BoundingBox(Point3 position, Point3 max, Point3 min);
	~BoundingBox();

	void draw() const;
	void drawFaces(int index, float x, float y, float z,float halfwidth, float halfheight, float halfdepth) const;
	void updateBoundaries();

	void setPosition(Point3 const & position);

	Point3 getCurPosition();
	float getBoxSize();

	Point3 getMax();
	Point3 getMin();

	void setCollide(bool a);

private:
	Point3 *cur_position;
	float height;
	float width;
	float depth;

	Point3 max;
	Point3 min;

	bool colliding;

};

/* todo class BoundingSphere : public BoundingVolume{
public:
	BoundingSphere(Point3 position, float radius);
	~BoundingSphere();
};*/

#endif // BOUNDINGBOX_H
