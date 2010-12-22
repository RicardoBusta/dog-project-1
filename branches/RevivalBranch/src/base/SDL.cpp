/*
 * sdl.cpp
 *  SDL Main Interface
 *  Static Class
 *  Created on: 01/09/2010
 *      Author: Cleobulo
 */
#include "SDL.h"

// Static Members
IMAGE* SDL::screen;
int SDL::width;
int SDL::height;
int SDL::bpp;
int SDL::FPS;
unsigned int SDL::timer_begin;
bool SDL::quit;
Keyboard SDL::key[SDLK_LAST];
list<int> SDL::modKey;
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

    //initialize SDL_Mix sound system
    if( Mix_OpenAudio(DEFAULT_SOUND_FREQUENCY, MIX_DEFAULT_FORMAT, 2, DEFAULT_CHUNK_SIZE) < 0)
    {
    	return false;
    }

    atexit(Mix_CloseAudio);

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

	//FOG
	  GLfloat density = 0.0005;
	  GLfloat fogColor[4] = {0.0, 0.0, 0.0, 1.0};
	  glEnable (GL_FOG);
	  glFogi (GL_FOG_MODE, GL_EXP2);
	  glFogfv (GL_FOG_COLOR, fogColor);
	  glFogf (GL_FOG_DENSITY, density);
	  glHint (GL_FOG_HINT, GL_NICEST);
	//end

	//BLENDING
	  glEnable(GL_BLEND);
	  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	  glEnable(GL_COLOR_MATERIAL);

	glShadeModel( GL_SMOOTH );

	projection( SCREEN_WIDTH , SCREEN_HEIGHT );
	return false;
}

void SDL::projection( int width , int height )
{
	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();
	//glOrtho( 0.0,width, 0.0,height , -FRUSTUM_DEPTH, FRUSTUM_DEPTH);
	glFrustum (-width/20,width/20, -height/20,height/20, 50,6000);

   glMatrixMode(GL_MODELVIEW);
}

IMAGE* SDL::loadImage( const char* filename )
{
    IMAGE *temp = NULL, *otm = NULL;

    temp = IMG_Load(filename);

    if(temp)
    {
      otm = SDL_DisplayFormatAlpha(temp);
      SDL_FreeSurface(temp);
    }

    return otm;
}
//loads a sound from the "filename" file
SOUND* SDL::loadSound( char *filename )
{
	SOUND* sound = NULL;

	//obs: the file type **MUST** be WAVE, MOD, RIFF, OGG, MP3 or VOC
	sound = Mix_LoadWAV(filename);
	return sound;
}

MODEL* SDL::loadModel( char* filename )
{
	MODEL* sound = NULL;
	return sound;
}

// Carrega texturas e retorna um handle
// TODO: criar um gerenciador de texturas, isso aqui só carrega
// Deve ser necessário criar parametros opcionais para o carregamento de textura
// Clamp, mipmap etc
// Sugestão: pra reduzir o tamanho da função, pode criar um parametro alpha, e
// quem carregar a textura(provavelmente sabe se tem transparencia) passa pra função
// Outro ponto: podemos retirar a verificação se é ou não BGR
GLuint SDL::loadTexture(const char *fileName)
{
	SDL_Surface *texSurface = NULL;		// Imagem da textura
	GLuint textureHandle 	= 0;		// Id opengl da textura
	GLenum texFormat 		= 0;		// Formato da imagem
	GLint nColors 			= 0;		// RGB ou RGBA?

	// Carrega a surface com a imagem
	texSurface = loadImage(fileName);

	if(texSurface)	// Carregou?
	{
		// Opcional: verificar se é NPOT(non power of two)
		nColors = texSurface->format->BytesPerPixel;
		if(nColors == 4)	// Alpha
		{
			if(texSurface->format->Rmask == 0x000000ff)
			{
				texFormat = GL_RGBA;
			}
			else
			{
				texFormat = GL_BGRA;
			}
		}
		else if(nColors == 3)	// Sem Alpha
		{
			if(texSurface->format->Rmask == 0x000000ff)
			{
				texFormat = GL_RGB;
			}
			else
			{
				texFormat = GL_BGR;
			}

		}
		// Opcional: verificar se não é truecolor. Necessário?

		// Podemos, gerar o handle, caso queiram.
		// Acho melhor deixar o opengl fazer isso.
		// Quantidade de handles gerados e variável que armazenará.
		glGenTextures(1, &textureHandle);
		// Torna aquele target um alias para a textura.
		// Até que outra seja bound ou essa seja deleted
		glBindTexture(GL_TEXTURE_2D, textureHandle);

		// Vamos usar MIPMAP?
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

		// Tem que ver se quer que a textura seja repetida ou "clampeada"
		// Modificar aqui com glTexParameterf usando o parametro GL_TEXTURE_WRAP_ S   e   T

		// Carrega a surface na textura e gera mipmaps automaticamente
		int result = gluBuild2DMipmaps(GL_TEXTURE_2D, nColors, texSurface->w, texSurface->h,
							texFormat, GL_UNSIGNED_BYTE, texSurface->pixels);

		if(result)
			printf("Falha ao carregar textura.\nGLU Error: %s\n", gluErrorString(result));
		// Limpa memória
		SDL_FreeSurface(texSurface);

		printf("Sucesso no carregamento da textura.\n");
	}
	else	// Erro ao carregar surface
	{
		printf("Falha ao carregar imagem.\n");
		return NULL;		// PODE ser necessário criar uma flag
	}
	return textureHandle;
}

void SDL::removeTexture(GLsizei n, const GLuint *textures)
{
	// Não nulo e maior que 0
	if(textures && n > 0)
		glDeleteTextures(n, textures);
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

void SDL::resize( int nwidth , int nheight )
{
	width = nwidth;
	height = nheight;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//int side=min(screen.width,screen.height);
	//glViewport((side-screen.width)/-2,(side-screen.height)/-2,side,side);
	glViewport(0,0,width, height);
	//adjust_frustum();
	//adjust_camera();
	glMatrixMode(GL_TEXTURE);
	//adjust_texture();
	glMatrixMode(GL_MODELVIEW);
}

void SDL::toggleFullScreen()
{

}

void SDL::actionsGet(){
	//resets every modified key to its original state.
	    list<int>::iterator it;
	    for (it=modKey.begin();it!=modKey.end();it++) {
	        key[(*it)].reset();
	    }
	    modKey.clear(); //clear the mod key list.
	    //mouse.reset(); //will reset the mouse state as well, when implemented.

	    while (SDL_PollEvent(&event)) {
	            switch (event.type) {
	            case SDL_QUIT:
	                quit = true;
	                break;
	            case SDL_MOUSEMOTION:
	                break;
	            case SDL_MOUSEBUTTONDOWN:
	                break;
	            case SDL_MOUSEBUTTONUP:
	                break;
	            case SDL_KEYDOWN:
	            	if(event.key.keysym.sym == SDLK_ESCAPE){
	            		actions.push_back( CON_QUIT_GAME );
	            		quit = true;
	            	}else{
	            		actions.push_back( CON_KEY_DOWN );
	            		key[event.key.keysym.sym].hit_=true;
	            		key[event.key.keysym.sym].down_=true;
	            		modKey.push_back(event.key.keysym.sym);
	            	}
	                break;
	            case SDL_KEYUP:
	            	actions.push_back( CON_KEY_UP );
	                key[event.key.keysym.sym].release_=true;
	                key[event.key.keysym.sym].down_=false;
	                modKey.push_back(event.key.keysym.sym);
	                break;
	            default:
	                break;
	            }
	        }
}

bool SDL::quitGame()
{
	return quit;
}

//Paint the canvas
void SDL::paint(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //calls the scene paint function here
    SDL_GL_SwapBuffers();
}

void SDL::prepareRender()
{
	// Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Put the correct matrix mode and current matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void SDL::swapBuffers()
{
	// Swap the buffers
	SDL_GL_SwapBuffers();
}
