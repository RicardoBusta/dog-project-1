/*
 * model.h
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#ifndef MODEL_H_
#define MODEL_H_

#include "content.h"

class Model: public Content {
public:
	Model();
	virtual ~Model();

	void draw();

	bool load();
};

#endif /* MODEL_H_ */
