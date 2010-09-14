/*
 * debugscene.cpp
 *
 *  Created on: 08/09/2010
 *      Author: Cleï¿½bulo
 */

#include "debugscene.h"

DebugScene::DebugScene()
{
	up = down = false;
}

DebugScene::~DebugScene() {
}

bool DebugScene::load()
{

	return true;
}

bool DebugScene::prepare()
{
	// Preparando os elementos
	ship = new Hero;
	this->entidades.push_back( ship );

	// Posicionando a câmera
	camera.moveOriginW( Vector3( -320.0f , -240.0f , 100.0f ) );
	camera.setRotationX( -90*16 );

	Box* cen;
	for( int i = 0 ; i < 100 ; i++ ){
		cen = new Box;
		cen->randomColors();
		cen->setData(70,20,130);
		cen->move(Vector3(0,-100, -i*260));
		this->entidades.push_back( cen );
	}

	return true;
}

bool DebugScene::unload()
{
	entidades.clear();

	return true;
}

void DebugScene::inputs()
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

			default:
				// Standby
				break;
		}
	}
}

void DebugScene::logic()
{
	// Moving the camera
	camera.moveOriginW( Vector3(0,0,-5) );

	if( up ) camera.setRotationY(3);
	if( down ) camera.setRotationY(-3);
	if( right ) ship->move( Vector3(3,0,0) );
	if( left ) ship->move( Vector3(-3,0,0) );

	ship->move( Vector3(0,0,-5) );
}

void DebugScene::render()
{
	// Render start
	SDL::prepareRender();

	//Position the objects in the camera
	glMultMatrixf( camera.getMatrixToThis() );

	// Render all the elements of the scene
	for( unsigned int i = 0 ; i < entidades.size() ; i++ )
		entidades[i]->render();

	// Switch the buffers
	SDL::switchBuffers();
}

SceneMessage DebugScene::result()
{
	// End the execution of the game
	return SCN_END_GAME;
}
