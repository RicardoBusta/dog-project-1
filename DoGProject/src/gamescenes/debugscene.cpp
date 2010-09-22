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

DebugScene::~DebugScene() {
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

bool DebugScene::load()
{
	glEnable(GL_TEXTURE_2D);
	Texture* newtex;
	SoundEffect *som;

	newtex = new Texture("madeira", "squareTex.jpg");

	newtex = new Texture("nave", "ship.png");

	newtex = new Texture("stars", "star_texture.jpg");


	som = new SoundEffect("tiro", "laser.ogg");
	som->setVolume(40);
	ContentManager::addContent(som);

	som = new SoundEffect("fundo", "background.ogg");
	som->setVolume(100);
	ContentManager::addContent(som);
	return true;
}

bool DebugScene::prepare()
{
	world = new Entity;
	this->scenario.push_back( world );
	// Preparando os elementos

	ship = new Hero();
	ship->move( Vector3(0,0,200) );
	ship->setModel(new ModelShip());
	this->ships.push_back(ship);
	//COLLISION TEST
	bvol2 = new BoundingBox
			(ship->getPosition()->x,ship->getPosition()->y,
					ship->getPosition()->z,50.0f,50.0f,50.0f);

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

bool DebugScene::unload()
{
	ContentManager::removeContent(CONTENT_TEXTURE, "madeira");
	ContentManager::removeContent(CONTENT_TEXTURE, "ship");
	ContentManager::removeContent(CONTENT_TEXTURE, "stars");
	glDisable(GL_TEXTURE_2D);

	list<Entity*>::iterator it;

	while (!ships.empty()){
			it = ships.begin();
			delete (*it);
			ships.pop_front();
		}
	while (!bullets.empty()){
				it = bullets.begin();
				delete (*it);
				bullets.pop_front();
			}
	while (!scenario.empty()){
				it = scenario.begin();
				delete (*it);
				scenario.pop_front();
			}

	return true;
}

void DebugScene::logic()
{
	if( up )	ship->moveForward();
	if( down )	ship->moveBackward();
	if( right )	ship->moveRight();
	if( left )	ship->moveLeft();
	if( !(left xor right) ) ship->handleTilt();

	if( shooting ){
		ship->handleShoot(&bullets);
	}
	ship->boundingVol->checkCollision((BoundingBox*)bvol2);

	list<Entity*>::iterator it;
	for(it=bullets.begin();it!=bullets.end();it++){
			(*it)->boundingVol->checkCollision((BoundingBox*)bvol2);
	}
	handleShips();
	handleBullets();
	handleScenario();
}

void DebugScene::render()
{
	// Render start
	SDL::prepareRender();
	//Position the objects in the camera
	glMultMatrixf( camera->getMatrixToThis() );
	// Render all the elements of the scene
	list<Entity*>::iterator it;
	bvol2->draw();
	for(it=ships.begin();it!=ships.end();it++){
			(*it)->render();
	}
	for(it=bullets.begin();it!=bullets.end();it++){
			(*it)->render();
	}
	for(it=scenario.begin();it!=scenario.end();it++){
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


