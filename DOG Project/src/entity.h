#ifndef ENTITY_H
#define ENTITY_H

class entity{
private:
	bool visible; //� visivel (vai ser desenhada)
	bool frozen; //N�o faz nada nem interage com outras entidades, mas ainda � desenhado na tela.
	bool live; //Est� viva (caso n�o esteja ser� removida de seu respectivo grupo)

//3D Model.
	bool hasModel;
	animatedModel *model;

//Posi��o da entidade em rela��o ao pai.
	struct position_{
		float x,y,z;
	}position;

//Rota��o da entidade em rela��o ao pai.
	struct rotation_{
			float x,y,z;
	}rotation;

//Escala do objeto em rela��o ao pai.
	struct scale_{
			float x,y,z;
	}scale;

//D�ficit de cor em rela��o ao pai. Default: (1,1,1) = cor normal. (0,0,0) preto.
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

//fun��es virtuais:
	virtual void draw()=0;
	virtual void
	virtual void handle()=0;
};

#endif //ENTITY_H
