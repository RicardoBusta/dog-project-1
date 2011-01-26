/*
 * model.h
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#ifndef MODEL_H_
#define MODEL_H_

#include "Content.h"

#include "../base/SDL.h"
#include "../base/md2.h"
#include "../math/Frame.h"
#include "../math/Point3.h"
#include "../math/Vector3.h"
#include "../base/Common.h"
#include "../contents/ContentManager.h"

class Model: public Content {
public:
	Model();
	virtual ~Model();

	void draw();

	bool load(std::string &);

	void setSkin(int skin);
	int skin;
private:
	struct MD2Data data;
};

#endif /* MODEL_H_ */
