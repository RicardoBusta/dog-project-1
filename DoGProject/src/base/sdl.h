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
#include <SDL/SDL_image.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_ttf.h>

#include <list>
using namespace std;

/* SE FOR USAR TTF
#define NORMAL TTF_STYLE_NORMAL
#define ITALICO TTF_STYLE_ITALIC
#define NEGRITO TTF_STYLE_BOLD

//funcionalidade utilizada pela TTF
enum textquality {solid, shaded, blended};*/

class SDL{
    public:

	// Construtor vazio
	SDL();

	// Preparando o SDL e o OPENGL e os encerrando
	static bool initialize();
	static void close();

	// Initializing subsystems
	static bool setVideo();
	static bool setAudio();

	// OpenGL Interface
	static bool initOpenGL();
	static void projection( int width , int height );


	// Carregando Arquivos
	static IMAGEM* loadImage( char* filename );
	static MUSICA* loadMusic( char* filename );
	static MODELO* loadModel( char* filename );

	// Timer Interface
	static void timerStart();
	static void timerStop();

	// Render Essentials
	static void refresh();

	// Extra
	static void resize( int width , int height );
	static void paint();
	static void toggleFullScreen();

	// Events interface
	static bool actionsLeft();
	static ControllerStatus nextAction();

    private:
	// Screen surface
	static IMAGEM* screen;

	// Events input and returns parameters
	static SDL_Event event;
	static list<ControllerStatus> actions; //depois me explica pra que serve isso

	// Properties
	static int width;
	static int height;
	static int bpp;

	// FPS control
	static int FPS;
	static int timer_begin;


//by Ricardo, só para testes.
public:
	static bool exec(void);
	static void events(void);
	static bool quit;
};

#endif /* SDL_H_ */
