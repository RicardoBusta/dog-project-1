////
//  Shader: represents a shader program. 
//  Created by: Fernando
////
 /*
 *  Represents a shader program: has methods to setup a shader program and install it in the pipeline 
 *  Created on: 20/10/2010
 *      Author: Fernando
 */

#ifndef SHADER_H
#define SHADER_H

#include "Content.h" // Base class: Content

class Shader : public Content {

public:
	// Initializates the Shader with two parameters, path to the vertex shader, path to the fragment shader
	Shader(string label, const char*, const char*);
	~Shader();
	// Installs this shader program into the pipeline
	void enable();
	// Uninstalls this shader program from the pipeline
	void disable();
protected:
	// Preprocesses the string containing the shader code with some special directives defined(We can put #include directives etc)
	// void preprocessShader(const char * );
	// Loads a shader and compiles it.
	GLuint loadShader(const char *fileName, GLenum shaderType);
	// Loads a fragment shader using loadShader
	void loadFragmentShader(const char *fileName);
	// Loads a vertex shader using loadShader
	void loadVertexShader(const char *fileName);
	// Loads a shader program(get the shader files and compiles them into a shader program.)
	GLuint loadShaderProgram(const char *vertShaderFile, const char *fragShaderFile);
private:
	GLuint shaderProgram;
	GLuint vertShader;
	GLuint fragShader;
};

#endif // SHADER_H
