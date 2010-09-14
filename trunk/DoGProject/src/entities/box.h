/*
 * box.h
 *  Um bloco qualquer
 *  Created on: 14/09/2010
 *      Author: Cleóbulo
 */

#ifndef BOX_H_
#define BOX_H_

#include "entity.h"
#include "../base/sdl.h"
#include "../math/point3.h"

class Box : public Entity {
public:
	Box();
	~Box();

	void randomColors();

	// box properties
	void setData( float width , float height , float depth );

	// Main reaction
	void selfHandler();

	// This render
	void draw();

private:
	void drawFace( int , int , int , int );

	float width,height,depth;

	float vr[8],vg[8],vb[8];
	Point3 vertex[8];
};

#endif /* BOX_H_ */
