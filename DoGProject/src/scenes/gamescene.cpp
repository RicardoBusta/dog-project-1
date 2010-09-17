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
}

void GameScene::handleEntities(){
	list<Entity*>::iterator it;
	for(it=entities.begin();it!=entities.end();it++){
		if( !(*it)->isLive() ){
			if((*it)->isVisible()){
				(*it)->toggleVisible();
			}
			//delete (*it);
			//entities.remove(it);
			//delete aux;
		}else{
			(*it)->handle();
		}
	}
}
