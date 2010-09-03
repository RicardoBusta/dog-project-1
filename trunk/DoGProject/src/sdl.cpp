/*
 * sdl.cpp
 *  SDL Main Interface
 *  Static Class
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
 */
#include "sdl.h"

// Static Members
IMAGEM* SDL::tela;
int SDL::width;
int SDL::height;
int SDL::bpp;
int SDL::FPS;
int SDL::timer_begin;
SDL_Event SDL::eventos;
list<ControllerStatus> SDL::acoes;

// Class implementation
SDL::SDL(){}

bool SDL::initialize()
{
	// Initializing the SDL

	// Default values
	SDL::width  	 = SCREEN_WIDTH;
	SDL::height 	 = SCREEN_HEIGHT;
	SDL::bpp    	 = SCREEN_BPP;
	SDL::FPS    	 = DEFAULT_FPS;
	SDL::total_acoes = 0;

	// Initializing the subsystems
	if( !setVideo() )
		return false;

	if( !setAudio() )
		return false;

	// At the ending
	atexit(SDL_Quit);

	// Everything's fine
	return true;
}

void SDL::close(){}

bool SDL::setVideo()
{
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		return false;
	}

	tela = SDL_SetVideoMode( width , height , bpp,
			SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL );

	if( tela == NULL )
	{
		return false;
	}

	return true;
}

bool SDL::setAudio()
{
    // Initialize the audio subsystem
    if ( SDL_Init( SDL_INIT_AUDIO ) < 0 )
    {
        return false;
    }
    // Audio initialized with sucess
    return true;
}

void SDL::initOpenGL()
{

}

void SDL::projection( int width , int height )
{

}

IMAGEM* SDL::loadImage( char* filename )
{
    IMAGEM *temp = NULL, *otm = NULL;

    temp = IMG_Load(filename);

    if(temp)
    {
      otm = SDL_DisplayFormatAlpha(temp);
      SDL_FreeSurface(temp);
    }

    return otm;
}

MUSICA* SDL::loadMusic( char* filename )
{
	MUSICA* nova;
	return nova;
}

MODELO* SDL::loadModel( char* filename )
{
	MODELO* novo;
	return novo;
}

void SDL::timerStart()
{
   // Get the current ticks
   timer_begin = SDL_GetTicks();
}

void SDL::timerStop()
{

   // The time variation
   int delta = (int)((SDL_GetTicks() - timer_begin));

   // Keep the frame rate
   if( delta < ( 1000 / FPS ) )
   {
         //Sleep the remaining frame time
          SDL_Delay( ( 1000 / FPS ) - delta );
   }
}

void SDL::refresh()
{
   //Update screen
   SDL_GL_SwapBuffers();
}

void SDL::resize( int width , int height )
{

}

void SDL::toggleFullScreen()
{

}

int SDL::actionsLeft()
{
	// Put the actions in a queue
	while( SDL_PollEvent( &eventos )){
		acoes.push_back( STANDBY ); // Add the action
	}

	// Return the size of the queue
	return (int) acoes.size();
}

static ControllerStatus SDL::nextAction(){

	// Returns the first action done
	return acao;
}
