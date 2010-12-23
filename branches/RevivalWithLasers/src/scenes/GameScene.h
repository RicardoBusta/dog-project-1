/*
 * gameScene.h
 *
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "Scene.h"
#include <list>
#include <vector>
using namespace std;

#include "../entities/Entity.h"
#include "../entities/Hero.h"
#include "../entities/Projectile.h"


class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
protected:
	// Main properties of a game
	Frame* camera;

	// All the scene entities
	list<Entity*> entities;

	// The entities in a classified manner
	Entity** world;
	Hero* ship;
	list<Projectile**> friendly;
	list<Projectile**> unfriendly;
	//list<Enemy**> enemys;
	//list<Item**> items;



	// Their handler
	void handleEntities();

	// The GameLoop implemented here
	void logic();
	void basicLogic();
	virtual void specificLogic() = 0;
	void render();

	// Some specific inputs of all the gamescenes
	void specificInput();

	// The default buttons configurations
	int up,down,left,right,shoot;
private:
	// Used to calculate the basicLogic, which turns impossible for the hero ship
	// to travel off the screen
	Point3 preShipPos;

};

#endif /* GAMESCENE_H_ */
