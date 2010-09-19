/*
 * ContentManager.cpp
 *
 *  Created on: 18/09/2010
 *      Author: fernando
 */

#include "contentmanager.h"

unordered_map<std::string, Content *> ContentManager::contents;
unordered_map<std::string, Content *>::iterator ContentManager::it;

// Retorna um content, NULL caso inexistente
Content* ContentManager::getContent(CONTENT_ type, std::string label)
{
	bool success = searchContent(type, label);
	if(success)
		return it->second;
	return NULL;
}

bool ContentManager::removeContent(CONTENT_ type, std::string label)	// Remove um content, false caso nao remova
{
	bool success = searchContent(type, label);
	if(success)
	{
		if(it->second->used() == false)
		{
			contents.erase(it);
			return true;
		}
		else
		{
			it->second->removeUser();
			return false;
		}
	}
	return false;
}
// Adiciona um content no fim da lista, true sucesso, false falhou
Content* ContentManager::addContent(Content *content)
{
	bool found = searchContent(content->getType(), content->getLabel());
	if(content)
	{
		if(found == false)
		{
			contents[content->getLabel().c_str()] = content;
			return content;					// Adicionou o próprio, retorna ele
		}
		else								// Já existe esse content
		{
			if(content) it->second->addUser();
			return it->second;
		}
	}
	return NULL;
}

// Busca um Content, true caso acha, false caso não. Preenche o iterator com o content.
bool ContentManager::searchContent(CONTENT_ type, std::string label)
{
	it = contents.find(label.c_str());
	if(it != contents.end())
		return true;
	else
		return false;
}
