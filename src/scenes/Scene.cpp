/*
 * scene.cpp
*	Base for the Game State. Main Loop Information Hiding.
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */

#include "Scene.h"

Scene::Scene(){
	Scene::running = true;
}

Scene::~Scene(){
}

void Scene::input()
{
	// The main inputs
	SDL::actionsGet();
	this->running = !SDL::quitGame();

	// The specifics inputs of the scene
	this->specificInput();
}

SceneMessage Scene::run(){
	// Read necessary data
	load();

	// Position all the elements as they might be
	prepare();

	// Main loop
	while( Scene::running ){

		SDL::timerStart();	// Start the frame rate control

		input();
		logic();
		render();

		SDL::timerStop(); 	// Keeps the frame rate control
	}

	// Destroy the unecessary data
	unload();

	// Return the next request
	return result();
}

bool Scene::isRunning() const
{
	return Scene::running;
}
