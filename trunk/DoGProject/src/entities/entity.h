/*
 * entity.h
 *	Entity Class, represents every entity inside the game.
 *	This includes projectiles, enemies and the controllable character.
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <list>

using namespace std;

class AnimatedModel;

class Entity{
private:
	bool visible; //� visivel (vai ser desenhada)
	bool frozen; //N�o faz nada nem interage com outras entidades, mas ainda � desenhado na tela.
	bool live; //Est� viva (caso n�o esteja ser� removida de seu respectivo grupo)

//3D Model.
	bool hasModel;
	animatedModel *model;

//Position (Parent Related)
	struct position_{
		float x,y,z;
	}position;

//Rotation (Parent Related)
	struct rotation_{
			float x,y,z;
	}rotation;

//Scale (Parent Related)
	struct scale_{
			float x,y,z;
	}scale;

//Color Usage (Default is (1,1,1)=Original Color, (0,0,0) stands for black)
	struct color_{
			float r,g,b;
	}color;

	void drawSons();
	void handleSons();
	void killSons();

	list<Entity*> sons;
public:
	Entity();
	//entity(entity *parent=NULL);
	~Entity();

	//Sets
	void setPosition(float x, float y, float z);
	void setPosition(entity *e);
	void move(float x, float y, float z);

	void setRotation(float x, float y, float z);
	void setRotation(entity *e);
	void rotate(float x, float y, float z);

	void setScale(float x, float y, float z);
	void setScale(entity *e);
	void resize(float x, float y, float z);

	void setColor(float r, float g, float b);
	void setColor(entity *e);
	void colorize(float r, float g, float b);

	void setModel(animatedModel* model);

	//Toggles
	void toggleVisible();
	void toggleLive();
	void toggleFrozen();

	//Virtual Functions:
	virtual void draw()=0;
	virtual void handle()=0;
};

#endif /* ENTITY_H_ */
