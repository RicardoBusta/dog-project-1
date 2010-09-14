/*
 * hero.h
 *	The main hero ship
 *  Created on: 13/09/2010
 *      Author: Cleóbulo
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

	// The main "reaction" function
	void selfHandler();

	// The main rendering function
	void draw();

};

#endif /* HERO_H_ */
