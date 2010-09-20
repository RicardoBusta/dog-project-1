/*
 * content.cpp
 *
 *  Created on: Sep 3, 2010
 *      Author: Ricardo
 */

#include "content.h"

Content::Content(std::string label, enum CONTENT_ con)
:users(1) {
	setType(con);
	setLabel(label);
}

Content::~Content() {
	// TODO Auto-generated destructor stub
}

void Content::setType(enum CONTENT_ t){
	type = t;
}

enum CONTENT_ Content::getType() const{
	return type;
}

bool Content::used(){
	//if( users.size() > 0 )
	if(users>0)
		return true;
	return false;

}

void Content::addUser(){
	users++;
}

void Content::removeUser(){
	if(used())
		users--;
}

string Content::getLabel() const{
	return label;
}

void Content::setLabel(string l){
	label = l;
}
