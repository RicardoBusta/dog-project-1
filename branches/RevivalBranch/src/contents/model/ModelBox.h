/*
 * ModelBox.h
 *
 *  Created on: 20/09/2010
 *      Author: ricardo
 */

//TODO when the model class is working properly, this one will not be needed anymore

#ifndef MODELBOX_H_
#define MODELBOX_H_

#include "../Model.h"

class ModelBox: public Model {
public:
	ModelBox();
	virtual ~ModelBox();

	void randomColors();

	//Box Properties
	void setData( float width , float height , float depth );
	void setTexture(string tex_label);

	void drawFace( int , int , int , int );

	float width,height,depth;

	float vr[8],vg[8],vb[8];
	Point3 vertex[8];

	void draw();
private:
	string label;
};

#endif /* MODELBOX_H_ */
