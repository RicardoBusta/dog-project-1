/*
 * content.h
 *	Content may be any loaded file, including textures, models and sounds.
 *  Created on: Sep 3, 2010
 *      Author: Ricardo
 */

#ifndef CONTENT_H_
#define CONTENT_H_

#include <string>

using namespace std;

enum CONTENT_{CONTENT_TEXTURE,CONTENT_MODEL,CONTENT_SOUNDEFFECT};

class Content {
private:
	string label;
	enum CONTENT_ type;
public:
	Content();
	virtual ~Content();

	string getLabel(); // Obtain the string that identifies this content.
	int getType();

	virtual bool load()=0; //Calls SDL::load functions depending on the type of information needed
};

#endif /* CONTENT_H_ */
