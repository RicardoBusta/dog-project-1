/*
 * scene.h
 *	Base for the Game State. Main Loop Information Hiding.
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "../base/util.h"
#include "../base/sdl.h"

class Scene {
public:
	Scene();
	virtual ~Scene();

	// Data preparation
	virtual bool load()    = 0;
	virtual bool prepare() = 0;
	virtual bool unload()  = 0;

	// Main call
	SceneMessage run();

	// Verify if its running
	bool isRunning();

	// GameLoop
	virtual void input() = 0;
	virtual void logic()  = 0;
	virtual void render() = 0;

	// Result of the scene
	virtual SceneMessage result() = 0;

	// Play a subscene
	/*static SceneMessage playScene( Scene* , LoopState );
	static SceneMessage playScene( SceneMessage );*/

protected:
	bool running;
};

#endif /* SCENE_H_ */
