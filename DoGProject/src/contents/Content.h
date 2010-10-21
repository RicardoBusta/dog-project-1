/*
 * content.h
 *	Content may be any loaded file, including textures, models and sounds.
 *  Created on: Sep 3, 2010
 *      Author: Ricardo
 */

#ifndef CONTENT_H_
#define CONTENT_H_

#include <string>
#include <fstream>
#include <list>
#include "../base/SDL.h"

using namespace std;

class Scene;

enum CONTENT_{CONTENT_TEXTURE,CONTENT_MODEL,CONTENT_SOUND, CONTENT_SHADER};

class Content {
private:
	string label;
	enum CONTENT_ type;
	int users;

public:
	Content(std::string label, enum CONTENT_ con);
	virtual ~Content();

	//Type Control
	void setType(enum CONTENT_ type);
	enum CONTENT_ getType() const;

	//User Control
	bool used(); //Check if the content is being used
	void addUser();
	void removeUser();

	//Label Control
	string getLabel() const; //Obtain the string that identifies this content.
	void setLabel(string label);

	virtual bool load(std::string &)=0; //Calls SDL::load functions depending on the type of information needed

};

#endif /* CONTENT_H_ */
