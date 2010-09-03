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

enum {CONTENT_TEXTURE,CONTENT_MODEL,CONTENT_SOUND};

class content {
private:
	string label;
	int type; //enum CONTENT_
public:
	content(string label="");
	virtual ~content();

	string getLabel();
	virtual void load()=0; //Calls SDL::load functions depending on the type of information needed
	virtual void clear()=0;
};

#endif /* CONTENT_H_ */
