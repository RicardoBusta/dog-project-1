/*
 * debugscene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Everybody
 */

#include "DebugScene.h"
#include "../base/Common.h"
#include "../entities/Hero.h"
#include "../entities/Box.h"

#include "../entities/Weapon.h"
#include "../contents/ContentManager.h"
#include "../contents/Model.h"
#include "../contents/model/ModelShip.h"
#include "../contents/model/ModelBox.h"
#include "../contents/model/ModelWeapon.h"
#include "../contents/model/ModelFromMD2.h"

#include "../physics/Physics.h"

DebugScene::DebugScene()
{
}

DebugScene::~DebugScene(){
}

bool DebugScene::load(){

	// Loading the necessary data
	Texture* newtex;
	SoundEffect *som;

	// Textures
	newtex = new Texture("nave", "ship.png");
	newtex = new Texture("enemy", "enemy.png");
	newtex = new Texture("madeira", "squareTex.jpg");
	newtex = new Texture("estrelas", "star_texture.jpg");

	// Shot sound
	som = new SoundEffect("tiro", "laser.ogg");
	som->setVolume(40);
	ContentManager::addContent(som);

	// Background music
	som = new SoundEffect("fundo", "background.ogg");
	som->setVolume(100);
	ContentManager::addContent(som);

	return true;
}

bool DebugScene::prepare(){
	// Double pointers guarantee that there will be no problem when an object
	// is remove from one list
	world = new Entity*;
	*world = new Entity;
	this->entities.push_back( *world );

	// World creation
	Box* cen;
	for( int i = 0 ; i < 6 ; i++ ){
		for(int j=-6;j<=6;j++){
			cen = new Box(*world);
			cen->move(Vector3(120*j,-100, -i*300-120*abs(j)));
			ModelBox *cen_model = new ModelBox();
			cen_model->setTexture("estrelas");
			cen->setModel(cen_model);
		}
	}

	// Hero Creation
	ship = new Hero();
	ship->move( Vector3(0,0,200) );
	Model* ship_model = new ModelShip();
	ship->setModel(ship_model);
	this->entities.push_back(ship);

	// Adding the weapons
	ship->addWeapon( Vector3(-10.0,-10.0, 0 ));
	ship->addWeapon( Vector3(10.0,-10.0, 0 ));

	// Positioning the camera
	camera->moveOriginW( Vector3( 0 , 800 , 0 ) );
	camera->setRotationX( -90 );

	// Playing the music background
	SoundEffect *fundo =  ContentManager::getSoundEffect("fundo");
	fundo->play(INF_LOOP);

	return true;
}

bool DebugScene::unload(){
	//todo function to remove all content from the hash map
	ContentManager::removeContent(CONTENT_TEXTURE, "madeira");
	ContentManager::removeContent(CONTENT_TEXTURE, "estrelas");
	ContentManager::removeContent(CONTENT_TEXTURE, "ship");
	ContentManager::removeContent(CONTENT_TEXTURE, "enemy");
	ContentManager::removeContent(CONTENT_TEXTURE, "objeto");
	return true;
}

void DebugScene::specificLogic(){


}

SceneMessage DebugScene::result(){
	// End the execution of the game
	return SCN_END_GAME;
}


