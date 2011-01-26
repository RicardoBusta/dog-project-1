/*
 * model.cpp
 *
 *  Created on: 18/09/2010
 *      Author: ricardo
 */

#include "../base/SDL.h"
#include "Model.h"
#include "../base/md2.h"
#include <iostream>
#include <GL/glu.h>


Model::Model() 
	:Content("",CONTENT_MODEL){		//MUDAR AQUI PRO LABEL, depois
	// TODO Auto-generated constructor stub
	skin = 0;
}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

void Model::draw() {
	struct Vertex vertex[3];
	unsigned char coords[3];
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,640,0,480);
    gluPerspective(45.0,640/480,0.01,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glBegin(GL_TRIANGLES);
	for(int i=0 ; i<data.header.numTriangles ; i++)
	{
		std::cout << "lendo " << i << "-esimo vertice" << std::endl;
		//le vertices do triangulo
		vertex[0] = data.frames[0].vertices[data.triangles[i].vertexIndex[0]];
		vertex[1] = data.frames[0].vertices[data.triangles[i].vertexIndex[1]];
		vertex[2] = data.frames[0].vertices[data.triangles[i].vertexIndex[2]];

		//desenha triangulo
		for(int j=0 ; j<3 ; j++)
		{
			coords[0] = (vertex[j].v[0] * data.frames[0].scale[0]) + data.frames[0].translate[0];
			coords[1] = (vertex[j].v[1] * data.frames[0].scale[1]) + data.frames[0].translate[1];
			coords[2] = (vertex[j].v[2] * data.frames[0].scale[2]) + data.frames[0].translate[2];
			glVertex3f(coords[0], coords[1], coords[2]);
		}
	}
	glEnd();
}

bool Model::load(string &file){

	string completePath = MODELSPATH;
	completePath.append(file);
	FILE *fp = fopen(completePath.c_str(), "rb");

	if(!fp)
	{
		std::cout << "Nao pode abrir o modelo" << std::endl;
		return false;
	}
	else
	{
		//le o cabecalho do arquivo md2
		fread(&(data.header), 1, sizeof( struct MD2Header), fp);

		//aloca memoria para os campos correspondentes
		data.skins = new struct Skin[data.header.numSkins];
		data.texcoords = new struct TextCoord[data.header.numTextureCoord];
		data.triangles = new struct Triangle[data.header.numTriangles];
		data.frames = new struct KeyFrame[data.header.numFrames];

		//aloca o vetor de vertices de cada frame
		for(int i=0 ; i<data.header.numFrames ; i++)
		{
			data.frames[i].vertices = new struct Vertex[data.header.numVertices];
		}

		//inicia o carregamento dos dados do arquivo md2

		//carrega skins
		fseek(fp, data.header.skinOffset, SEEK_SET);
		if(fread(data.skins, sizeof(struct Skin), data.header.numSkins, fp) != data.header.numSkins)
		{
			std::cout << "Erro ao carregar skins" << std::endl;
			return false;
		}

		//carrega coordenadas de textura
		fseek(fp, data.header.textCoordOffset, SEEK_SET);
		if(fread(data.texcoords, sizeof(struct TextCoord), data.header.numTextureCoord, fp) != data.header.numTextureCoord)
		{
			std::cout << "Erro ao carregar coordenadas de textura" << std::endl;
			return false;
		}

		//carrega triangulos
		fseek(fp, data.header.triangleOffset, SEEK_SET);
		if(fread(data.triangles, sizeof(struct Triangle), data.header.numTriangles, fp) != data.header.numTriangles)
		{
			std::cout << "Erro ao carregar triangulos" << std::endl;
			return false;
		}

		//carrega frames
		fseek(fp, data.header.frameOffset, SEEK_SET);
		for(int i=0 ; i<data.header.numFrames ; i++)
		{
			fread(data.frames[i].scale, sizeof(float), 3, fp);
			fread(data.frames[i].translate, sizeof(float), 3, fp);
			fread(data.frames[i].name, sizeof(char), 16, fp);
			fread(data.frames[i].vertices, sizeof(struct Vertex), data.header.numVertices, fp);
		}

		fclose(fp);
	}

	return true;
}

void Model::setSkin(int newskin){
	skin = newskin;
}
