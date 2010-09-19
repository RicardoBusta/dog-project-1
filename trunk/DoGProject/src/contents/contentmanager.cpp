/*
 * ContentManager.cpp
 *
 *  Created on: 18/09/2010
 *      Author: fernando
 */

#include "contentmanager.h"

list<Content*> ContentManager::contents;
list<Content*>::iterator ContentManager::it;

// Retorna um content, NULL caso inexistente
Content* ContentManager::getContent(CONTENT_ type, std::string label)
{
	bool success = searchContent(type, label);
	if(success)
		return *it;
	return NULL;
}

bool ContentManager::removeContent(CONTENT_ type, std::string label)	// Remove um content, false caso nao remova
{
	bool success = searchContent(type, label);
	if(success)
	{
		if((*it)->used() == false)
		{
			contents.erase(it);
			return true;
		}
		else
		{
			(*it)->removeUser();
			return false;
		}
	}
	return false;
}
// Adiciona um content no fim da lista, true sucesso, false falhou
bool ContentManager::addContent(Content *content)
{
	bool found = searchContent(content->getType(), content->getLabel());
	if(content)
	{
		if(found == false)
		{
			contents.push_back(content);
			return true;
		}
		else
		{
			if(content) (*it)->addUser();
			return false;
		}
	}
	return false;
}

// Busca um Content, NULL caso inexistente
bool ContentManager::searchContent(CONTENT_ type, std::string label)
{
	for (it = contents.begin(); it != contents.end(); it++)
	{
		if(type == (*it)->getType() && label == (*it)->getLabel())
			return true;
	}
	return false;
}

