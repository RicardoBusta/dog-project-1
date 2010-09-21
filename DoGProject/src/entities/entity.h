/*
 * entity.h
 *	Entity Class, represents every entity inside the game.
 *	This includes projectiles, enemies and the controllable character.
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "../base/sdl.h"
#include "../math/frame.h"
#include "../math/point3.h"
#include "../math/vector3.h"
#include "../base/util.h"
#include <list>

using namespace std;

class Model;

class Entity{
private:

protected:
	Entity *parent;
	bool visible; //It is visible and will be drawn
	bool frozen; //Does not interact with other entities, but is still drawn in the screen.
	bool live; //If it's alive by the end of it's handling, will not be removed.

//3D Model.
	Model *model;
	//AnimatedModel *model;

	// Frame
	Frame coords;

//Scale (Parent Related)
	struct scale_{
			float x,y,z;
	}scale;

//Color Usage (Default is (1,1,1)=Original Color, (0,0,0) stands for black)
	struct color_{
			float r,g,b;
	}color;

	void clearChildren();

	list<Entity*> sons;
public:
	//Entity();
	Entity(Entity *parent=NULL);
	virtual ~Entity();

	Entity* getParent();

	//Sets
	void setPosition( Point3 position );
	//void setPosition(entity *e);
	void move( Vector3 delta ); //Move the object based on its father coordinates
	void moveSelf( Vector3 delta ); //Move the object based on it's own coordinate system
	Point3 *getPosition();

	void setRotation(float x, float y, float z);
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);

	void rotate(float x, float y, float z);
	void rotateX(float x);
	void rotateY(float y);
	void rotateZ(float z);

	Point3 getRotation();
	float getRotationX();
	float getRotationY();
	float getRotationZ();

	void setScale(float x, float y, float z);
	//void setScale(entity *e);
	void resize(float x, float y, float z);

	void setColor(float r, float g, float b);
	//void setColor(entity *e);
	//void colorize(float r, float g, float b);

	void setModel(Model* model);

	//Toggles
	void toggleVisible();
	void toggleLive();
	void toggleFrozen();

	//Check status
	bool isLive() const;
	bool isFrozen() const;
	bool isVisible() const;

	// Main operations
	void render();
	void handle();

	//Virtual Functions:
	virtual void handler();
};

#endif /* ENTITY_H_ */
