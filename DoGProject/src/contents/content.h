/*
 * content.h
 *	Content may be any loaded file, including textures, models and sounds.
 *  Created on: Sep 3, 2010
 *      Author: Ricardo
 */

#ifndef CONTENT_H_
#define CONTENT_H_

#include <string>
#include <list>
using namespace std;

class Scene;

enum CONTENT_{CONTENT_TEXTURE,CONTENT_MODEL,CONTENT_SOUNDEFFECT};

class Content {
private:
	string label;
	enum CONTENT_ type;
	int users;

public:
	Content();
	virtual ~Content();

	//Type Control
	void setType(enum CONTENT_ type);
	enum CONTENT_ getType();

	//User Control
	bool used(); //Check if the content is being used
	void addUser();
	void removeUser();

	//Label Control
	string getLabel(); //Obtain the string that identifies this content.
	void setLabel(string label);

	virtual bool load()=0; //Calls SDL::load functions depending on the type of information needed
};

#endif /* CONTENT_H_ */
