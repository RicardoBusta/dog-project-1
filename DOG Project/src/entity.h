/*
 * entity.h
 *	Entity Class, represents every entity inside the game.
 *	This includes projectiles, camera, enemies and the controllable character.
 *  Created on: Sep 2, 2010
 *      Author: Ricardo
 */

#ifndef ENTITY_H_
#define ENTITY_H_

class entity{
private:
	bool visible; //É visivel (vai ser desenhada)
	bool frozen; //Não faz nada nem interage com outras entidades, mas ainda é desenhado na tela.
	bool live; //Está viva (caso não esteja será removida de seu respectivo grupo)

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

public:
	entity(entity &parent=NULL);
	~entity();

	//Sets
	void setPosition(float x, float y, float z);
	void move(float x, float y, float z);

	void setRotation(float x, float y, float z);
	void rotate(float x, float y, float z);

	void setScale(float x, float y, float z);
	void resize(float x, float y, float z);

	void setColor(float r, float g, float b);
	void colorize(float r, float g, float b);

	void setModel(animatedModel* model);

	//Toggles
	void toggleVisible();
	void toggleLive();
	void toggleFrozen();

	//Virtual Functions:
	virtual void draw()=0;
	virtual void
	virtual void handle()=0;
};

#endif /* ENTITY_H_ */
