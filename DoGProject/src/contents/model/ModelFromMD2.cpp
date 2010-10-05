/*
 * ModelFromMD2.cpp
 *
 *  Created on: 05/10/2010
 *      Author: ricardo
 */

#include "ModelFromMD2.h"
#include "MD2Loader.h"

ModelFromMD2::ModelFromMD2() {
	Obj = new MD2Obj();
	if( Obj->Load( "resources/models/test_models/dumbster.md2" ) ){
		cout << "deu pau" << endl;
		//return true;
	}

	CurFrame = 0;
	Frames = Obj->GetFrameCount();

	string a("objeto");
	Texture *tex = ContentManager::getTexture(a);
	Obj->SetTexture(tex->getHandle());//*/
}

ModelFromMD2::~ModelFromMD2() {
	delete Obj;
}

void ModelFromMD2::draw(){
	glPushMatrix();
	glRotated(-90, 0,1,0);
	glRotated(-90, 1,0,0);
	Obj->Draw(CurFrame);
	CurFrame++;
	 if(CurFrame>=Frames){
	     CurFrame=0;
	 }
	 glPopMatrix();
}
