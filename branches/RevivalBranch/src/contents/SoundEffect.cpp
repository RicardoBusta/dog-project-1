/*
 * SoundEffect.cpp
 *
 *  Created on: 19/09/2010
 *      Author: felipe
 */

#include "ContentManager.h"
#include "SoundEffect.h"
#include "../base/SDL.h"
#include <SDL/SDL_mixer.h>
#include <string>

SoundEffect::SoundEffect(std::string label, std::string path) 
	:Content(label,CONTENT_TEXTURE), currentChannel(0)
{
	if(path != "")
	{
		this->load(path);
		ContentManager::addContent( this );

	}
}

SoundEffect::~SoundEffect() {
	// TODO Auto-generated destructor stub
}

bool SoundEffect::load(std::string &filename)
{
	string completePath = SOUNDSPATH;
	completePath.append(filename);

	this->som = Mix_LoadWAV(completePath.c_str());

	return this->som != NULL;
}

bool SoundEffect::play(enum NLOOPS n)
{
	if((this->currentChannel = Mix_PlayChannel(-1, this->som, n)) < 0)
	{
		return false;
	}

	return true;
}

bool SoundEffect::stop()
{
	if(Mix_HaltChannel(this->currentChannel) < 0)
	{
		return false;
	}

	return true;
}

void SoundEffect::setVolume(Uint8 vol)
{
	this->som->volume = vol;
}

Uint8 SoundEffect::getVolume()
{
	return this->som->volume;
}

void SoundEffect::incVolume()
{
	if(this->som->volume < 128)
		this->som->volume++;

}

void SoundEffect::decVolume()
{
	if(this->som->volume>0)
		this->som->volume--;
}

bool SoundEffect::fadeIn(int ms, enum NLOOPS n)
{
	if(Mix_FadeInChannel(this->currentChannel, this->som, ms, n) < 0)
	{
		return false;
	}

	return true;
}

bool SoundEffect::fadeOut(int ms)
{
	if( Mix_FadeOutChannel(this->currentChannel, ms ) < 0)
	{
		return false;
	}

	return true;
}
