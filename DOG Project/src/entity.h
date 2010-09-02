#ifndef ENTITY_H
#define ENTITY_H

class entity{
private:
	bool visible; //É visivel (vai ser desenhada)
	bool frozen; //Não faz nada nem interage com outras entidades, mas ainda é desenhado na tela.
	bool live; //Está viva (caso não esteja será removida de seu respectivo grupo)

//3D Model.
	bool hasModel;
	animatedModel *model;

//Posição da entidade em relação ao pai.
	struct position_{
		float x,y,z;
	}position;

//Rotação da entidade em relação ao pai.
	struct rotation_{
			float x,y,z;
	}rotation;

//Escala do objeto em relação ao pai.
	struct scale_{
			float x,y,z;
	}scale;

//Déficit de cor em relação ao pai. Default: (1,1,1) = cor normal. (0,0,0) preto.
	struct color_{
			float r,g,b;
	}color;

public:
	entity(entity &parent=NULL);
	~entity();

	void setPosition(float x, float y, float z);
	void move(float x, float y, float z);

	void setRotation(float x, float y, float z);
	void rotate(float x, float y, float z);

	void setScale(float x, float y, float z);
	void resize(float x, float y, float z);

	void setColor(float r, float g, float b);
	void colorize(float r, float g, float b);

	void setModel(animatedModel* model);

	void toggleVisible();
	void toggleLive();
	void toggleFrozen();

//funções virtuais:
	virtual void draw()=0;
	virtual void
	virtual void handle()=0;
};

#endif //ENTITY_H
