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
#include <list>

using namespace std;

class AnimatedModel;

class Entity{

protected:
	bool visible; //ï¿½ visivel (vai ser desenhada)
	bool frozen; //Nï¿½o faz nada nem interage com outras entidades, mas ainda ï¿½ desenhado na tela.
	bool live; //Estï¿½ viva (caso nï¿½o esteja serï¿½ removida de seu respectivo grupo)

//3D Model.
	bool hasModel;
	AnimatedModel *model;

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

	void killSons();

	list<Entity*> sons;
public:

	// Comentei tudo o que ainda não sei como seria implementado,
	// ou não é necessário para a primeira versão


	Entity();
	//entity(entity *parent=NULL);
	virtual ~Entity();

	//Sets
	void setPosition( Point3 position );
	//void setPosition(entity *e);
	void move( Vector3 delta );

	void setRotation(float x, float y, float z);
	//void setRotation(entity *e);
	void rotate(float x, float y, float z);

	void setScale(float x, float y, float z);
	//void setScale(entity *e);
	void resize(float x, float y, float z);

	void setColor(float r, float g, float b);
	//void setColor(entity *e);
	//void colorize(float r, float g, float b);

	//void setModel(AnimatedModel* model);

	//Toggles
	void toggleVisible();
	void toggleLive();
	void toggleFrozen();

	// Main operations
	void render();
	void handler();

	//Virtual Functions:
	virtual void draw()=0;
	virtual void selfHandler()=0;
};

#endif /* ENTITY_H_ */
