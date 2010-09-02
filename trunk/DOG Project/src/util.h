/*
 * util.h
 *	Padrões e Enumerações
 *  Created on: 01/09/2010
 *      Author: Cleóbulo
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

enum GameStatus{ RUNNING , PAUSED , GAME_OVER , END_OF_STAGE , LAST_GAME_STATUS};

enum SceneMessage{ SCN_INITIAL_STATE , SCN_END_GAME , SCN_MAIN_MENU , SCN_OPTIONS_MENU ,
					SCN_STAGE_1 ,
					SCN_DEBUG_STAGE };

enum ControllerStatus{ STANDBY , RIGHT_ON , RIGHT_OFF , LEFT_ON , LEFT_OFF ,
		UP_ON , UP_OFF , DOWN_ON , DOWN_OFF , SHOTING_ON , SHOTING_OFF , LAST_CONTROLLER_STATUS };

enum PersonagemStatus{ STANDBY , MOVING , SHOTING , DEAD , LAST_PERSONAGEM_STATUS };

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
