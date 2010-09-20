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

	//Main reaction
	void handler();

};

#endif /* BOX_H_ */
