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

	Texture* newtex;
	SoundEffect *som;

	newtex = new Texture("nave", "ship.png");
	newtex = new Texture("enemy", "enemy.png");
	newtex = new Texture("madeira", "squareTex.jpg");
	newtex = new Texture("estrelas", "star_texture.jpg");

	som = new SoundEffect("tiro", "laser.ogg");
	som->setVolume(40);
	ContentManager::addContent(som);

	som = new SoundEffect("fundo", "background.ogg");
	som->setVolume(100);
	ContentManager::addContent(som);

	return true;
}

bool DebugScene::prepare(){
	world = new Entity;
	this->entities.push_back( world );


	ship = new Hero();
	ship->move( Vector3(0,0,200) );
	Model* ship_model = new ModelShip();
	ship->setModel(ship_model);
	this->entities.push_back(ship);

	//Weapon *weapon;
	ship->addWeapon( Vector3(-10.0,-10.0, 0 ));
	ship->addWeapon( Vector3(10.0,-10.0, 0 ));

	// Posicionando a camera
	camera->moveOriginW( Vector3( 0 , 800 , 0 ) );
	camera->setRotationX( -90 );

	Box* cen;
	//Model* boxm = new ModelBox(); assim basta 1 modelo, mas ai todas as caixas terão a mesma cor
	for( int i = 0 ; i < 6 ; i++ ){
		for(int j=-6;j<=6;j++){
			cen = new Box(world);
			cen->move(Vector3(120*j,-100, -i*300-120*abs(j)));
			ModelBox *cen_model = new ModelBox();
			cen_model->setTexture("estrelas");
			cen->setModel(cen_model);
		}
	}

	//TODO remodelar de forma que não seja necessário fazer esse cast
	SoundEffect *fundo =  reinterpret_cast<SoundEffect *>(ContentManager::getContent(CONTENT_SOUND, "fundo"));
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
	glDisable(GL_TEXTURE_2D);

	list<Entity*>::iterator it;

	while (!entities.empty()){
			it = entities.begin();
			delete (*it);
			entities.pop_front();
		}

	return true;
}

void DebugScene::specificLogic(){


}

SceneMessage DebugScene::result(){
	// End the execution of the game
	return SCN_END_GAME;
}


