/*
 * box.h
 *  Um bloco qualquer
 *  Created on: 14/09/2010
 *      Author: Cle�bulo
 */

#ifndef BOX_H_
#define BOX_H_

#include "entity.h"
#include "../contents/contentmanager.h"

class Box : public Entity {
public:
	Box(Entity* parent=NULL);
	~Box();

	void randomColors();

	//Box Properties
	void setData( float width , float height , float depth );

	//Main reaction
	void handleSelf();

	//The drawing function
	void draw();

private:
	void drawFace( int , int , int , int );

	float width,height,depth;

	float vr[8],vg[8],vb[8];
	Point3 vertex[8];
};

#endif /* BOX_H_ */
