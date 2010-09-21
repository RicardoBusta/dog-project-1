/*
 * gameScene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */

#include "gamescene.h"
#include "../math/frame.h"

GameScene::GameScene() {
	camera = new Frame();
}

GameScene::~GameScene(){
	delete camera;
}

void GameScene::handleShips(){
	list<Entity*>::iterator it;
	for(it=ships.begin();it!=ships.end();it++){
		if( !(*it)->isLive() ){
			list<Entity*>::iterator it2;
			it2 = it;
			it--;
			delete (*it2);
			ships.erase(it2);
		}else{
			(*it)->handle();
		}
	}
}

void GameScene::handleBullets(){
	list<Entity*>::iterator it;
	for(it=bullets.begin();it!=bullets.end();it++){
		if( !(*it)->isLive() ){
			list<Entity*>::iterator it2;
			it2 = it;
			it--;
			delete (*it2);
			bullets.erase(it2);
		}else{
			(*it)->handle();
		}
	}
}

void GameScene::handleScenario(){
	list<Entity*>::iterator it;
	for(it=scenario.begin();it!=scenario.end();it++){
		if( !(*it)->isLive() ){
			list<Entity*>::iterator it2;
			it2 = it;
			it--;
			delete (*it2);
			scenario.erase(it2);
		}else{
			(*it)->handle();
		}
	}
}
