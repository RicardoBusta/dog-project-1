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

	// Default controllers
	up = SDLK_UP;
	down = SDLK_DOWN;
	left = SDLK_LEFT;
	right = SDLK_RIGHT;
	shoot = SDLK_SPACE;
}

GameScene::~GameScene(){
	delete camera;
	delete ship;
	entities.clear();
	friendly.clear();
	unfriendly.clear();
}

void GameScene::specificInput(){

	preShipPos = ship->getPosition();

	// Ship movement
	if( SDL::key[up].down() )
		ship->moveForward();
	if( SDL::key[down].down() )
		ship->moveBackward();
	if( SDL::key[right].down() )
		ship->moveRight();
	if( SDL::key[left].down() )
		ship->moveLeft();
}

void GameScene::logic(){
	// Now the logic is based in two stages
	this->basicLogic();
	this->specificLogic();
}

void GameScene::basicLogic(){

	// Basic Movement
	// Auxiliary positions
	Point3 shipPos, newPos;

	// Old position
	shipPos = ship->getPosition();
	newPos = shipPos;
	shipPos = camera->convertP( shipPos , camera->getMatrixToThis() );

	// Valid the position of the ship
	if( shipPos.getX()-55 < -SCREEN_WIDTH or shipPos.getX()+55 > SCREEN_WIDTH )
		newPos.setX( preShipPos.getX() );

	if(	shipPos.getY()-70 < -SCREEN_HEIGHT or shipPos.getY()+2 > SCREEN_HEIGHT )
		newPos.setZ( preShipPos.getZ());

	ship->setPosition(newPos);

	// Ship tilt
	if( !( SDL::key[left].down() xor SDL::key[right].down() ) )
		ship->handleTilt();

	// Shooting handler
	if( SDL::key[shoot].down() )
		ship->handleShoot(&entities,&friendly);

	// The Entities being handle
	handleEntities();
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

void GameScene::render(){

	// Render start
	SDL::prepareRender();
	//Position the objects in the camera
	glMultMatrixf( camera->getMatrixToThis() );
	// Render all the elements of the scene
	list<Entity*>::iterator it;

	for(it=entities.begin();it!=entities.end();it++){
			(*it)->render();
	}
	// Swap the buffers
	SDL::swapBuffers();
}
