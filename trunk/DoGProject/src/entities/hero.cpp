/*
 * hero.cpp
 *
 *  Created on: 13/09/2010
 *      Author: Cle�bulo
 */

#include "hero.h"
#include "../contents/contentmanager.h"
#include "../contents/ModelWeapon.h"
#include "../entities/weapon.h"

Hero::Hero(Entity* p):Entity(p) {
	shootCoolDown = 0;
	speed = 5;
	volume = new BoundingBox(this->getPosition(), 120.0f,50.0f,180.0f);
}

Hero::~Hero() {
}

void Hero::addAction( ControllerStatus control ){

}

void Hero::handler()
{
	if(shootCoolDown>=0)
		shootCoolDown--;
}

void Hero::draw()
{
	volume->setCurPosition(this->getPosition());
	volume->draw();


	/*glColor3f(color.r,color.g,color.b);
	std::string a("nave");
	Texture *tex = (Texture *) ContentManager::getContent(CONTENT_TEXTURE, a);
	if(tex == NULL)
	{
		printf("Textura com erro.\n");
	}
	tex->bind();

	//sca 5 5 5
	//cen 0 0 0.7
	glPushMatrix();
	glScalef(80,80,80);

	glBegin(GL_TRIANGLES);
		//BRIDGE
			//side 1
			glTexCoord2d(0,1);
			glVertex3f(0, 0, 0);
			glTexCoord2d(0,0);
			glVertex3f(-0.25, 0, 1);
			glTexCoord2d(0.5,0);
			glVertex3f(0, 0.25, 1);
			//side 2
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0,0);
			glVertex3f( 0.25, 0, 1 );

		//ENGINE
			glTexCoord2d(1,1);
			glVertex3f( 0, 0.25, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( -0.25, 0, 1 );
			glTexCoord2d(1,0.5);
			glVertex3f( 0.25, 0, 1 );

		//WINGS
		//upside
			//left
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,0);
			glVertex3f( -0.75, 0, 1 );
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			//right
			glTexCoord2d(0,1);
			glVertex3f( 0, 0, 0.5);
			glTexCoord2d(0.5,1);
			glVertex3f( 0, 0, 1 );
			glTexCoord2d(0.5,0);
			glVertex3f( 0.75, 0, 1 );
		//Tail
			triangle(	0 , 0.35 , 1,
						0 , 0 , 1,
						0 , 0 , 0.3
					);
			triangle(	0 , 0.35 , 1,
						0 , 0 , 0.3,
						0 , 0 , 1
					);
		//downside
			//wings
			triangle( 	-0.15, 0, 0.6,
						-0.25, 0, 1,
						-0.75, 0, 1
					);
			triangle( 	0.15, 0, 0.6,
						0.75, 0, 1,
						0.25, 0, 1
					);
			//middle
			triangle( 	0, 0, 0,
						0.25, 0, 1,
						-0.25, 0, 1
					);
	glEnd();
	glPopMatrix();*/
}

void Hero::moveForward(){
	move( Vector3(0,0,-speed) );
}
void Hero::moveBackward(){
	move( Vector3(0,0,speed) );
}
void Hero::moveLeft(){
	move( Vector3(-speed,0,0) );
	if(getRotationZ() < 45 ){
		rotateZ(2);
	}
}
void Hero::moveRight(){
	move( Vector3(speed,0,0) );
	if(getRotationZ() > -45 ){
		rotateZ(-2);
	}
}
void Hero::handleTilt(){
	if(getRotationZ() > 1){
		rotateZ(-1);
	}else if(getRotationZ() < -1){
		rotateZ(1);
	}else{
		setRotationZ(0);
	}
}

void Hero::handleShoot(){
	if (shootCoolDown<=0){
		list<Weapon*>::iterator it;
		for(it=weapons.begin();it!=weapons.end();it++){
			(*it)->shoot();
		}
		shootCoolDown = 10;
		//TODO remodelar de forma que não seja necessário fazer esse cast
		SoundEffect *tiro = reinterpret_cast<SoundEffect *>(ContentManager::getContent(CONTENT_SOUND, "tiro"));
		tiro->play(PLAY_ONCE);
	}
}

void Hero::addWeapon( Vector3 v ){
	Weapon *weapon = new Weapon(this);
	weapons.push_back(weapon);
	weapon->move(v);
	weapon->setModel(new ModelWeapon());
}
