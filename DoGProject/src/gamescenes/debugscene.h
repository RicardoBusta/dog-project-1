/*
 * debugScene.h
 *	Box with the airship and some enemies.
 *	Basic test scene.
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */

#ifndef DEBUGSCENE_H_
#define DEBUGSCENE_H_

#include "../scenes/gamescene.h"
#include "../entities/hero.h"
#include "../math/frame.h"
#include "../entities/box.h"
#include <vector>
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
	void inputs();
	void logic();
	void render();

	// Result of the scene
	SceneMessage result();

private:
	// Some test info
	Frame camera;
	Hero* ship;
	vector<Entity*> entities;

	bool up,down,left,right;
};

#endif /* DEBUGSCENE_H_ */
