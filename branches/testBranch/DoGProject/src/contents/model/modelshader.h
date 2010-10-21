#ifndef MODELSHADER_H
#define MODELSHADER_H

#include "../Model.h" // Base class: Model
#include "../shader.h"
#include <array>

// Gambiarra só pra testar VBO, enquanto não tem um loader
struct Vertex {
	float position[3];
	float color[3];
};

class ModelShader : public Model {

public:
	ModelShader(const char *vert, const char *frag);
	virtual ~ModelShader();
	void draw();
private:
	GLuint vbo;		// VBO to store the model
	Shader shader;
	std::array<GLfloat, 16> projection;
	std::array<GLfloat, 16> modelview;
};

#endif // MODELSHADER_H
