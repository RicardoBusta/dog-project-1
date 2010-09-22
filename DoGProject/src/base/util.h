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
#include <iostream>
using namespace std;

// Redefinitions
#ifndef REDEFINITIONS_HERE
#define REDEFINITIONS_HERE

#define GAME_TITLE "SpaceShips vs Zombies"
#define DEFAULT_FPS 60
#define IMAGE SDL_Surface
#define LOAD_IMAGE IMG_load
//#define MUSIC Mix_Music
//#define TEXTURESPATH "trunk/DoGProject/resources/textures/"
//#define SOUNDSPATH "trunk/DoGProject/resources/sounds/"
#define TEXTURESPATH "resources/textures/"
#define SOUNDSPATH "resources/sounds/"
#define SOUND Mix_Chunk
#define DEFAULT_SOUND_FREQUENCY 22050
#define DEFAULT_CHUNK_SIZE 1024
#define MODEL void*
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FRUSTUM_DEPTH 1000
#define SCREEN_BPP 32

#endif

#define DEBUG 1				// Ainda estamos debugando, sugestão do bustamante

void debug(string s0="",string s1="", string s2="", string s3="", string s4="", string s5="", string s6="", string s7="", string s8="", string s9="");

// Enumerations

enum GameStatus{ GAME_RUNNING , GAME_PAUSED , GAME_OVER , GAME_END_OF_STAGE , GAME_LAST_GAME_STATUS};

enum SceneMessage{ SCN_INITIAL_STATE , SCN_END_GAME , SCN_MAIN_MENU , SCN_OPTIONS_MENU ,
					SCN_STAGE_1 ,
					SCN_DEBUG_STAGE };

enum ControllerStatus{
	// No button pressed
	CON_STANDBY ,

	// Directional buttons
	CON_RIGHT_ON , CON_RIGHT_OFF , CON_LEFT_ON , CON_LEFT_OFF ,
	CON_UP_ON , CON_UP_OFF , CON_DOWN_ON , CON_DOWN_OFF ,

	// Action buttons
	CON_SHOOTING_ON , CON_SHOOTING_OFF , CON_CONFIRM_ON , CON_CONFIRM_OFF ,

	// Other buttons
	CON_QUIT_GAME , CON_LAST_CONTROLLER_STATUS };

enum PersonagemStatus{ PER_STANDBY , PER_MOVING , PER_SHOTING , PER_DEAD , PER_LAST_PERSONAGEM_STATUS };

enum NLOOPS { INF_LOOP=-1, PLAY_ONCE=0 };

enum EntityType { HERO_SHIP, ENEMY_SHIP, FRIENDLY_PROJECTILE, ENEMY_PROJECTILE };

// Useful Structures

typedef struct pl_mess_{

} PlayerMessage;

typedef struct mess_{

} Message;

typedef struct gmess_{

} GameMessage;

typedef struct ctr_{

} Controller;

//ANGLE OPERATIONS
float rad(float deg);
float deg(float rad);

float abs(float n);

#endif /* UTIL_H_ */
