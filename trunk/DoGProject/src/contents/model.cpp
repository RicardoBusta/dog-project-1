/*
 * model.cpp
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#include "model.h"

Model::Model() 
	:Content("",CONTENT_MODEL){		//MUDAR AQUI PRO LABEL, depois
	// TODO Auto-generated constructor stub
	skin = 0;
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

bool Model::load(std::string &){
	// TODO load a model
	return false;
}

void Model::setSkin(int newskin){
	skin = newskin;
}
