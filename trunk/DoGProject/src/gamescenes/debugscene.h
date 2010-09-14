/*
 * debugScene.h
 *	Caixa preta com a nave e alguns inimigos
 *	Servirá como a cena de testes mais básica
 *  Created on: 08/09/2010
 *      Author: Cleóbulo
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
	vector<Entity*> entidades;

	bool up,down,left,right;
};

#endif /* DEBUGSCENE_H_ */
