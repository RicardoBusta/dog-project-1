/*
 * debugscene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Everybody
 */

#include "debugscene.h"

#include "../entities/hero.h"
#include "../entities/box.h"
#include "../contents/contentmanager.h"
#include "../contents/model.h"
#include "../contents/ModelShip.h"
#include "../contents/ModelBox.h"


DebugScene::DebugScene()
{
	up = down = left = right = shooting = false;
}

DebugScene::~DebugScene() {
}

bool DebugScene::load()
{
	glEnable(GL_TEXTURE_2D);

	Texture* newtex;
	//SoundEffect *som;

	newtex = new Texture("madeira", "squareTex.jpg");

	newtex = new Texture("nave", "ship.png");

	newtex = new Texture("stars", "star_texture.jpg");


	//som = new SoundEffect("tiro", "laser.ogg");
	//ContentManager::addContent(som);

	//som = new SoundEffect("fundo", "background.ogg");
	//ContentManager::addContent(som);

	return true;
}

bool DebugScene::prepare()
{
	world = new Entity;
	this->entities.push_back( world );
	// Preparando os elementos
	ship = new Hero(world);
	ship->move( Vector3(0,0,200) );
	ship->setModel(new ModelShip());
/*
	Box *gun = new Box(ship);
	gun->randomColors();
	gun->setData(20,1,20);
	gun->toggleFrozen(); //Freezes the box in place
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
	//SoundEffect *fundo = (SoundEffect*)ContentManager::getContent(CONTENT_SOUND, "fundo");
	//fundo->play(INF_LOOP);

	return true;
}

bool DebugScene::unload()
{
	ContentManager::removeContent(CONTENT_TEXTURE, "madeira");
	ContentManager::removeContent(CONTENT_TEXTURE, "ship");
	ContentManager::removeContent(CONTENT_TEXTURE, "stars");
	glDisable(GL_TEXTURE_2D);

	list<Entity*>::iterator it;

	while (!entities.empty()){
			it = entities.begin();
			delete (*it);
			entities.pop_front();
		}

	return true;
}

void DebugScene::input()
{
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

void DebugScene::logic()
{
	SoundEffect *tiro;

	if( up )	ship->moveForward();
	if( down )	ship->moveBackward();
	if( right )	ship->moveRight();
	if( left )	ship->moveLeft();
	if( !(left xor right) ) ship->handleTilt();


	if( shooting ){
		ship->handleShoot();
		//TODO remodelar de forma que não seja necessário fazer esse cast
		//tiro = (SoundEffect*)ContentManager::getContent(CONTENT_SOUND, "tiro");
		//tiro->play(PLAY_ONCE);
	}
	handleEntities();
}

void DebugScene::render()
{
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

SceneMessage DebugScene::result()
{
	// End the execution of the game
	return SCN_END_GAME;
}


