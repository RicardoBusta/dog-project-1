/*
 * scene.cpp
*	Base for the Game State. Main Loop Information Hiding.
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */

#include "scene.h"

Scene::Scene(){
	Scene::running = true;
}

Scene::~Scene(){
}

SceneMessage Scene::run(){
	// Read necessary data
	load();

	// Position all the elements as they might be
	prepare();

	// Main loop
	while( Scene::running ){

		SDL::timerStart();	// Start the frame rate control

		inputs();
		logic();
		render();

		SDL::timerStop(); 	// Keeps the frame rate control
	}

	// Destroy the unecessary data
	unload();

	// Return the next request
	return result();
}

bool Scene::isRunning()
{
	return Scene::running;
}
