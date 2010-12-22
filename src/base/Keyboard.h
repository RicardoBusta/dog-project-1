/*
 * Keyboard.h
 *
 *  Created on: 25/09/2010
 *      Author: ricardo
 */

//#include "sdl.h"

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard {
	friend class SDL;
private:
	bool hit_;
	bool release_;
	bool down_;

	void reset(); //Resets the key state
public:
	Keyboard();
	virtual ~Keyboard();

	bool hit(); //Check if the key was hit that loop
	bool release(); //Check if the key was released that loop
	bool down(); //Check if the key is currently down
};

#endif /* KEYBOARD_H_ */
