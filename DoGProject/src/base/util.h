/*
 * util.h
 *	Enumerations and Patterns
 *  Created on: 01/09/2010
 *      Author: Cleobulo
 */

#ifndef UTIL_H_
#define UTIL_H_

class SDL;

#include <list>

// Redefinitions
#ifndef REDEFINITIONS_HERE
#define REDEFINITIONS_HERE

#define DEFAULT_FPS 60
#define IMAGEM SDL_Surface
#define CARREGAR_IMAGEM IMG_load
#define MUSICA void*
#define MODELO void*
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32
#define USE_OPENGL SDL_OPENGL

#endif


// Enumerations

enum GameStatus{ GAME_RUNNING , GAME_PAUSED , GAME_OVER , GAME_END_OF_STAGE , GAME_LAST_GAME_STATUS};

enum SceneMessage{ SCN_INITIAL_STATE , SCN_END_GAME , SCN_MAIN_MENU , SCN_OPTIONS_MENU ,
					SCN_STAGE_1 ,
					SCN_DEBUG_STAGE };

enum ControllerStatus{ CON_STANDBY , CON_RIGHT_ON , CON_RIGHT_OFF , CON_LEFT_ON , CON_LEFT_OFF ,
	CON_UP_ON , CON_UP_OFF , CON_DOWN_ON , CON_DOWN_OFF , CON_SHOTING_ON , CON_SHOTING_OFF , CON_LAST_CONTROLLER_STATUS };

enum PersonagemStatus{ PER_STANDBY , PER_MOVING , PER_SHOTING , PER_DEAD , PER_LAST_PERSONAGEM_STATUS };

// Useful Structures

typedef struct pl_mess_{

} PlayerMessage;

typedef struct mess_{

} Message;

typedef struct gmess_{

} GameMessage;

typedef struct ctr_{

} Controller;


#endif /* UTIL_H_ */
