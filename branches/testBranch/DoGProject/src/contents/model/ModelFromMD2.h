/*
 * ModelFromMD2.h
 *
 *  Created on: 05/10/2010
 *      Author: ricardo
 */

#ifndef MODELFROMMD2_H_
#define MODELFROMMD2_H_

#include "../Model.h"

class MD2Obj;

class ModelFromMD2:public Model {
public:
	ModelFromMD2();
	virtual ~ModelFromMD2();

	MD2Obj *Obj;

	int Frames;
	int CurFrame;

	void draw();
};

#endif /* MODELFROMMD2_H_ */
