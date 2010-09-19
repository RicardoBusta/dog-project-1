/*
 * gameScene.h
 *
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "scene.h"
#include <list>
#include <vector>
using namespace std;

#include "../entities/entity.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
protected:
	Frame* camera;

	list<Entity*> entities;

	void handleEntities();
private:

};

#endif /* GAMESCENE_H_ */
