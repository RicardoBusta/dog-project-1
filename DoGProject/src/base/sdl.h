/*
 * sdl.h
 *  SDL Main Interface
 *  Static Class
 *  Created on: 01/09/2010
 *      Author: Cleobulo
 */

#ifndef SDL_H_
#define SDL_H_

#include "util.h"
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <list>

#include "keyboard.h"

using namespace std;

/* SE FOR USAR TTF
#define NORMAL TTF_STYLE_NORMAL
#define ITALIC TTF_STYLE_ITALIC
#define BOLD TTF_STYLE_BOLD

//funcionalidade utilizada pela TTF
enum textquality {solid, shaded, blended};*/

class SDL{
public:
	SDL();

	//Initializing and closing SDL and OPENGL
	static bool initialize();
	static void close();

	//Initializing subsystems
	static bool setVideo();
	static bool setAudio();

	//OpenGL Interface
	static bool initOpenGL();
	static void projection( int width , int height );


	//Loading Files
	static IMAGE* loadImage( const char* filename );
	//static MUSIC* loadBackgroundMusic( char* filename );
	static SOUND* loadSound(char *filename);
	static MODEL* loadModel( char* filename );
	static GLuint loadTexture(const char *fileName);
	static void removeTexture(GLsizei n, const GLuint *textures);

	// Timer Interface
	static void timerStart();
	static void timerStop();

	// Render Essentials
	static void refresh();

	// Extra
	static void resize( int width , int height );
	static void paint();
	static void toggleFullScreen();

	//Keyboard state
	static Keyboard key[SDLK_LAST]; //Vector with the current key state
	static list<int> modKey; //Modified keys

	// Events interface
	static void actionsGet();
	static bool actionsLeft();
	static ControllerStatus nextAction();

	// Render functions
	static void prepareRender();
	static void swapBuffers();

    private:
	// Screen surface
	static IMAGE* screen;

	// Events input and returns parameters
	static SDL_Event event;
	static list<ControllerStatus> actions; //depois me explica pra que serve isso

	// Properties
	static int width;
	static int height;
	static int bpp;

	// FPS control
	static int FPS;
	static unsigned int timer_begin;


//by Ricardo, só para testes.
public:
	static bool quit;
};

#endif /* SDL_H_ */
