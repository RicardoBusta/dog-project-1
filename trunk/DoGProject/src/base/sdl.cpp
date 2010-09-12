/*
 * sdl.cpp
 *  SDL Main Interface
 *  Static Class
 *  Created on: 01/09/2010
 *      Author: Cleobulo
 */
#include "sdl.h"

// Static Members
IMAGEM* SDL::screen;
int SDL::width;
int SDL::height;
int SDL::bpp;
int SDL::FPS;
int SDL::timer_begin;
bool SDL::quit;
SDL_Event SDL::event;
list<ControllerStatus> SDL::actions;

SDL::SDL(){}

bool SDL::initialize()
{
	// Initializing the SDL

	// Default values
	SDL::width  	 = SCREEN_WIDTH;
	SDL::height 	 = SCREEN_HEIGHT;
	SDL::bpp    	 = SCREEN_BPP;
	SDL::FPS    	 = DEFAULT_FPS;
	SDL::quit		 = false;
	//SDL::total_acoes = 0; ???

	// Initializing the subsystems
	if( !setVideo() )
		return false;

	// Sets the window caption
	SDL_WM_SetCaption( GAME_TITLE , NULL);

	// Initializing the audio
	if( !setAudio() )
		return false;

	if( !initOpenGL() )
		return false;

	// At the ending
	atexit(SDL_Quit);

	// Everything's fine
	return true;
}

void SDL::close(){
	SDL_Quit();
}

bool SDL::setVideo()
{
	// Initializing the SDL video
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		return false;
	}

	// Main properties
	screen = SDL_SetVideoMode( width , height , bpp,
			SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_OPENGL );

	// If failed to create a screen surface
	if( screen == NULL )
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

bool SDL::initOpenGL()
{
	// Initializing the properties
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glEnable(GL_NORMALIZE);
	return false;
}

void SDL::projection( int width , int height )
{
	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();
	glOrtho( 0.0	,	640.0,
             0.0	,	480.0,
            -1000.0	,	1000.0);

   glMatrixMode(GL_MODELVIEW);
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

bool SDL::actionsLeft()
{
	// Put the actions in a queue

	while( SDL_PollEvent( &event )){

		switch( event.type ){
		case SDL_QUIT:
			// Quit the game
			actions.push_back( CON_QUIT_GAME );
			break;

		case SDL_KEYDOWN:
			break;

		case SDL_KEYUP:
			break;

		case SDL_MOUSEMOTION:
			break;

		}
	}

	// Return the size of the queue
	return (int)actions.size() > 0;
}


ControllerStatus SDL::nextAction(){
	// Returns the first action done
	if( 0 == (int)actions.size() )
		return CON_STANDBY;
	else{
		// Returns the first and take it out of the pile
		ControllerStatus nxt = actions.front();
		actions.pop_front();
		return nxt;
	}
}

//Paint the canvas
void SDL::paint(){

}

//The event catching function. While there's an event in the event list, handle it.
void SDL::events(){
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
        	switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					quit = true;
					break;
        	}
        	break;
        default:
        	//Do Nothing
			break;
        }
    }

}

//The Main SDL execution LOOP. Returns 0 if no errors occurs.
bool SDL::exec(){
	initialize();
	while( !quit ){
		events();
		paint();
	}
	close();
	return 0;
}
