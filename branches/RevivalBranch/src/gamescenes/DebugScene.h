/*
 * debugScene.h
 *	Box with the airship and some enemies.
 *	Basic test scene.
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
 */

#ifndef DEBUGSCENE_H_
#define DEBUGSCENE_H_

#include "../scenes/GameScene.h"

class Hero;
class Box;

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
	void specificLogic();
	void clean();

	// Result of the scene
	SceneMessage result();

private:
	// Some test info
	Entity* world;
	BoundingVolume *bvol2;


};

#endif /* DEBUGSCENE_H_ */
