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

#include "Content.h"
#include <string>
using namespace std;

#include "Texture.h"
#include "Model.h"
#include "SoundEffect.h"

// Estrutura contendo a função de comparação usada na hashtable
// Ia usar hash_compare<string>, mas por algum motivo, não está inclusa no compilador aqui ._.
struct compKey
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1,s2) == 0;
	}
};

// Classe do tipo static que possui metodos para gerenciar uma hashtable de contents
class ContentManager {
public:
	static Content* addContent(Content *);				// Recebe o tipo e a string, retorna o content, null caso content null
	static Content* getContent(CONTENT_, std::string );	// Retorna um content, NULL caso inexistente
	static Texture* getTexture( std::string );
	//static Model* getModel( std::string );
	static SoundEffect* getSoundEffect( std::string );
	static bool removeContent(CONTENT_, std::string );	// Remove um content, false caso nao remova

private:
	static inline bool searchContent(CONTENT_, std::string);	// Busca um Content, true ou false, armazena em it

	static unordered_map<std::string, Content *> contents;
	static unordered_map<std::string, Content *>::iterator it;
};


#endif /* CONTENTMANAGER_H_ */
