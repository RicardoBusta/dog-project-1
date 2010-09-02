/*
 * scene.h
 *	A base para os estados do jogo, encapsula o loop principal
 *
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */

#ifndef SCENE_H
#define SCENE_H

#include "util.h"
#include "sdl.h"

class Scene {
public:
	Scene();
	virtual ~Scene();

	// Data preparation
	virtual bool load();
	virtual bool prepare();
	virtual bool unload();

	// Main call
	SceneMessage run();

	// GameLoop
	void inputs();
	virtual void logic();
	virtual void render();

	// Result of the scene
	virtual SceneMessage result();

	// Play a subscene
	/*static SceneMessage playScene( Scene* , LoopState );
	static SceneMessage playScene( SceneMessage );*/

protected:
	bool running;
};

#endif // SCENE_H
