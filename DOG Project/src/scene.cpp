/*
 * scene.cpp
*	Base for the Game State. Main Loop Information Hiding.
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */

#include "scene.h"

Scene::Scene() { running = true; }

SceneMessage Scene::run(){

	// Read necessary data
	load();

	// Main loop
	while( Scene::running ){

		inputs();
		logic();
		render();
	}

	// Destroy the unecessary data
	unload();

	// Return the next request
	return result();
}
