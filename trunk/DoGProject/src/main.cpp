//============================================================================
// Name        : DoG Project 1
// Author      : DOG
// Version     : 1.0
// Description : Spaceships vs Zombies
//============================================================================

#include "base/sdl.h"
#include "gamescenes/debugscene.h"

int main( int argc , char* argv[] ) {
	//return SDL::exec();

	SDL::initialize();

	DebugScene *teste = new DebugScene;

	teste->run();

	SDL::close();
	
	delete teste;
	
	return 0;
}
