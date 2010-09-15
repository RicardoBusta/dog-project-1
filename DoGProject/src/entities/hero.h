/*
 * hero.h
 *	The main hero ship
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#ifndef HERO_H_
#define HERO_H_

#include "entity.h"
#include "../base/util.h"

class Hero : public Entity
{
public:
	Hero();
	~Hero();

	void addAction( ControllerStatus control );

	// The drawing function
	void draw();

private:
	// The main "reaction" function
	void handleSelf();
};

#endif /* HERO_H_ */
