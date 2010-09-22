/*
 * ContentManager.h
 *
 *  Created on: 18/09/2010
 *      Author: fernando
 */
#define _DEFINE_DEPRECATED_HASH_CLASSES 0

#ifdef WIN
#include <boost/tr1/unordered_map.hpp>
#else
#include <tr1/unordered_map>
using namespace std::tr1;
#endif


#ifndef CONTENTMANAGER_H_
#define CONTENTMANAGER_H_

#include "content.h"
#include <string>
using namespace std;

#include "texture.h"
#include "model.h"
#include "soundeffect.h"

struct compKey
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1,s2)==0;
	}
};

class ContentManager {
public:
	static Content* addContent(Content *);		// Recebe o tipo e a string, retorna o content, null caso content null
	static Content* getContent(CONTENT_, std::string );	// Retorna um content, NULL caso inexistente
	static bool removeContent(CONTENT_, std::string );	// Remove um content, false caso nao remova

private:
	static inline bool searchContent(CONTENT_, std::string);	// Busca um Content, true ou false, armazena em it

	static unordered_map<std::string, Content *> contents;
	static unordered_map<std::string, Content *>::iterator it;
};


#endif /* CONTENTMANAGER_H_ */
