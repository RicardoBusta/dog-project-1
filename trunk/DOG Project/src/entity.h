#ifndef ENTITY_H
#define ENTITY_H

class entity{
private:
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
	entity(entity &parent);

//Função que desenha a entidade, caso ela possua um modelo.
	draw();
};

#endif //ENTITY_H
