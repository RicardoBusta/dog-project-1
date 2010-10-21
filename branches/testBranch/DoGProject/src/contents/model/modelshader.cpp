#include "modelshader.h"

ModelShader::ModelShader(const char *vert, const char *frag)
	:shader("testeShader", vert, frag)
{
}

ModelShader::~ModelShader()
{
	glDeleteBuffers(1, &vbo);
}

void ModelShader::draw()
{
	glPushMatrix();
	glScalef(80,80,80);
	shader.enable();
	
	glBegin(GL_TRIANGLES);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 2.0, 0.0);
		glVertex3f(-1.0, 0.0, 0.0);
		glVertex3f(-1.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 2.0, 0.0);
	glEnd();
	shader.disable();
	glPopMatrix();
}
