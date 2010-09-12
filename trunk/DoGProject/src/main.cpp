//============================================================================
// Name        : DoG Project 1
// Author      : DOG
// Version     : 1.0
// Description : Spaceships vs Zombies
//============================================================================

#include <iostream>
using namespace std;

#include "base/sdl.h"

int main( int argc , char* argv[] ) {

	SDL::initialize();

	bool sair = false;
	while( !sair ){

		while( SDL::actionsLeft() ){
			if( SDL::nextAction() == CON_QUIT_GAME )
				sair = true;
		}
	}

	SDL::close();

	return 0;
}
