/*
 * SoundEffect.h
 *
 *  Created on: 19/09/2010
 *      Author: felipe
 */

#ifndef SOUNDEFFECT_H_
#define SOUNDEFFECT_H_

#include "Content.h"

class SoundEffect: public Content {
public:
	SoundEffect(std::string label, std::string path);
	virtual ~SoundEffect();

	bool load(std::string &);
	bool play(enum NLOOPS);
	bool stop();

	//ajuste de volume - varia de 0 a 128
	void setVolume(Uint8 vol);
	Uint8 getVolume();
	void incVolume();
	void decVolume();

	//efeitos de fade-in e fade-out
	bool fadeIn(int ms, enum NLOOPS);
	bool fadeOut(int ms);

private:
	SOUND *som;
	int currentChannel;
};

#endif /* SOUNDEFFECT_H_ */
