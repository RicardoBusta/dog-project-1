/*
 * debugscene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Everybody
 */

#include "debugscene.h"
#include "../base/util.h"
#include "../entities/hero.h"
#include "../entities/box.h"
#include "../entities/weapon.h"
#include "../entities/bounding_volume.h"
#include "../contents/contentmanager.h"
#include "../contents/model.h"
#include "../contents/ModelShip.h"
#include "../contents/ModelBox.h"
#include "../contents/ModelWeapon.h"


DebugScene::DebugScene()
	: ship(NULL),world(NULL),up(false), down(false), right(false), shooting(false)
{
}

DebugScene::~DebugScene(){
}

void DebugScene::input(){
	// The main inputs
	while( SDL::actionsLeft() ){

		// The next action
		switch( SDL::nextAction() ){

			// Close the game action
			case CON_QUIT_GAME:
				// End the scene
				this->running = false;
				break;

			// Directional
			case CON_UP_ON:
				up = true;
				ship->addAction( CON_UP_ON );
				break;
			case CON_UP_OFF:
				up = false;
				ship->addAction( CON_UP_OFF );
				break;
			case CON_DOWN_ON:
				down = true;
				ship->addAction( CON_DOWN_ON );
				break;
			case CON_DOWN_OFF:
				down = false;
				ship->addAction( CON_DOWN_OFF );
				break;
			case CON_LEFT_ON:
				left = true;
				ship->addAction( CON_LEFT_ON );
				break;
			case CON_LEFT_OFF:
				left = false;
				ship->addAction( CON_LEFT_OFF );
				break;
			case CON_RIGHT_ON:
				right = true;
				ship->addAction( CON_RIGHT_ON );
				break;
			case CON_RIGHT_OFF:
				right = false;
				ship->addAction( CON_RIGHT_OFF );
				break;
			case CON_SHOOTING_ON:
				shooting = true;
				ship->addAction( CON_SHOOTING_ON );
				break;
			case CON_SHOOTING_OFF:
				shooting = false;
				ship->addAction( CON_SHOOTING_OFF );
				break;

			default:
				// Standby
				break;
		}
	}
}

bool DebugScene::load(){
	glEnable(GL_TEXTURE_2D);
	Texture* newtex;
	SoundEffect *som;

	newtex = new Texture("madeira", "squareTex.jpg");

	newtex = new Texture("nave", "ship.png");

	newtex = new Texture("stars", "star_texture.jpg");

	newtex = new Texture("enemy", "enemy.png");


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
	// Preparando os elementos

	ship = new Hero();
	ship->move( Vector3(0,0,200) );
	Model* lol = new ModelShip();
	ship->setModel(lol);
	this->entities.push_back(ship);
	//COLLISION TEST
	bvol2 = new BoundingBox
			(ship->getPosition().getX(),ship->getPosition().getY(),
					ship->getPosition().getZ(),50.0f,50.0f,50.0f, ship);

	//Weapon *weapon;
	for(int i=-50;i<=50;i+=10){
		ship->addWeapon( Vector3(i,0,abs(i)) );
	}
	/*
	Box *gun = new Box(ship);

	gun->setPosition( Point3(0,40,-10) );*/

	// Posicionando a camera
	camera->moveOriginW( Vector3( 0 , 200 , 400 ) );
	camera->setRotationX( -45 );

	Box* cen;
	//Model* boxm = new ModelBox(); assim basta 1 modelo, mas ai todas as caixas terão a mesma cor
	for( int i = 0 ; i < 4 ; i++ ){
		for(int j=-5;j<=5;j++){
			cen = new Box(world);
			cen->move(Vector3(80*j,-100, -i*300-80*j));
			cen->setModel(new ModelBox());
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
	ContentManager::removeContent(CONTENT_TEXTURE, "ship");
	ContentManager::removeContent(CONTENT_TEXTURE, "stars");
	ContentManager::removeContent(CONTENT_TEXTURE, "enemy");
	glDisable(GL_TEXTURE_2D);

	list<Entity*>::iterator it;

	while (!entities.empty()){
			it = entities.begin();
			delete (*it);
			entities.pop_front();
		}

	return true;
}

void DebugScene::logic(){
	if( up )	ship->moveForward();
	if( down )	ship->moveBackward();
	if( right )	ship->moveRight();
	if( left )	ship->moveLeft();
	if( !(left xor right) ) ship->handleTilt();

	if( shooting ){
		ship->handleShoot(&entities);
	}
	ship->boundingVol->checkCollision((BoundingBox*)bvol2);

	list<Entity*>::iterator it;
	for(it=entities.begin();it!=entities.end();it++){

	if((*it)->boundingVol!=NULL){
			(*it)->boundingVol->checkCollision((BoundingBox*)bvol2);
			(*it)->boundingVol->setCurPosition( (*it)->boundingVol->owner->getPosition() );
	}
	}
	handleEntities();
}

void DebugScene::render(){
	// Render start
	SDL::prepareRender();
	//Position the objects in the camera
	glMultMatrixf( camera->getMatrixToThis() );
	// Render all the elements of the scene
	list<Entity*>::iterator it;
	bvol2->draw();
	for(it=entities.begin();it!=entities.end();it++){
			(*it)->render();
	}
	// Swap the buffers
	SDL::swapBuffers();
}

SceneMessage DebugScene::result(){
	// End the execution of the game
	return SCN_END_GAME;
}


