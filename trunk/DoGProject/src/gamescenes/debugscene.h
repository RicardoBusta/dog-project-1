/*
 * debugScene.h
 *	Box with the airship and some enemies.
 *	Basic test scene.
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
 */

#ifndef DEBUGSCENE_H_
#define DEBUGSCENE_H_

#include "../scenes/gamescene.h"
#include "../entities/hero.h"
#include "../math/frame.h"
#include "../entities/box.h"
#include <list>
using namespace std;

class DebugScene : public GameScene
{
public:
	DebugScene();
	virtual ~DebugScene();

	// Preparations for the scene
	bool load();
	bool prepare();
	bool unload();

	// GameLoop
	void input();
	void logic();
	void render();

	// Result of the scene
	SceneMessage result();

private:
	// Some test info
	Frame camera;
	Hero* ship;
	list<Entity*> entities;
	void handleEntities();

	bool up,down,left,right,shooting;
};

#endif /* DEBUGSCENE_H_ */
