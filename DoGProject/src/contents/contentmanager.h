/*
 * ContentManager.h
 *
 *  Created on: 18/09/2010
 *      Author: fernando
 */

#ifndef CONTENTMANAGER_H_
#define CONTENTMANAGER_H_

#include "content.h"
#include <list>
#include <string>

#include "texture.h"
#include "model.h"
#include "soundeffect.h"

class ContentManager {
public:

	static Content* getContent(CONTENT_, std::string );	// Retorna um content, NULL caso inexistente
	static bool removeContent(CONTENT_, std::string );	// Remove um content, false caso nao remova
	static bool addContent(Content *);		// Recebe o tipo e a string, falso caso nao adicione
	static bool searchContent(CONTENT_, std::string);	// Busca um Content, true ou false, armazena em it

private:
	static list<Content*> contents;
	static list<Content*>::iterator it;	// Iterator auxiliar usado em search

};

#endif /* CONTENTMANAGER_H_ */
