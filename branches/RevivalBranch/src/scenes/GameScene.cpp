/*
 * gameScene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Cle�bulo
 */

#include "GameScene.h"
#include "../math/Frame.h"

GameScene::GameScene() {
	camera = new Frame();
}

GameScene::~GameScene(){
	delete camera;
}

void GameScene::handleEntities(){
	list<Entity*>::iterator it;
	for(it=entities.begin();it!=entities.end();it++){
		if( !(*it)->isLive() ){
			list<Entity*>::iterator it2;
			it2 = it;
			it--;
			delete (*it2);
			entities.erase(it2);
		}else{
			(*it)->handle();
		}
	}
}
