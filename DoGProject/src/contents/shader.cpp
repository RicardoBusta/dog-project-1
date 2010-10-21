#include "shader.h"
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>

// Initializates the Shader with two parameters, path to the vertex shader, path to the fragment shader
Shader::Shader(string label, const char *vertPath, const char *fragPath)
	: Content(label, CONTENT_SHADER), shaderProgram(0), vertShader(0), fragShader(0)
{
	if(vertPath != NULL and fragPath != NULL)
	{
		shaderProgram = loadShaderProgram(vertPath, fragPath);
	}
}
Shader::~Shader()
{
	glUseProgram(0);
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragShader);
	glDeleteShader(vertShader);
}
// Preprocesses the string containing the shader code with some special directives defined(We can put #include directives etc)
// void preprocessShader(const char * );
// Loads a shader and compiles it.
GLuint Shader::loadShader(const char *fileName, GLenum shaderType)
{
	std::string source;
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open())
    {
		file.seekg(0, std::ios::end);
		unsigned int fileSize = static_cast<unsigned int>(file.tellg());
		source.resize(fileSize);
		file.seekg(0, std::ios::beg);
		file.read(&source[0], fileSize);
    }
	else
	{
		return 0;
	}
	
    GLuint shader = glCreateShader(shaderType);
    const GLchar *convSource = reinterpret_cast<const GLchar *>(source.c_str());

    glShaderSource(shader, 1, &convSource, 0);

    return shader;
}
// Loads a fragment shader using loadShader
void Shader::loadFragmentShader(const char *fileName)
{
	fragShader = loadShader(fileName, GL_FRAGMENT_SHADER);
}
// Loads a vertex shader using loadShader
void Shader::loadVertexShader(const char *fileName)
{
	vertShader = loadShader(fileName, GL_VERTEX_SHADER);
}
// Loads a shader program(get the shader files and compiles them into a shader program.)
GLuint Shader::loadShaderProgram(const char *vertShaderFile, const char *fragShaderFile)
{
	ofstream log("Shaderlog.txt");
	GLint compiled = 0;
	GLint linked = 0;
	GLsizei errLength = 0;
	GLchar *errorMSG = NULL;
	
	loadVertexShader(vertShaderFile);
	glCompileShader(vertShader);
	
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compiled);
	// Error during shader compilation
	if(compiled == 0)
	{
		glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &errLength);
		errorMSG = new char[errLength+1];	// +1 for the null terminating character
		glGetShaderInfoLog(vertShader, errLength, NULL, errorMSG);
		string temp(errorMSG);
		log << "Vertex Shader Log: \n" << temp;
		delete errorMSG;
		log.close();
		return 0;
	}
	
	loadFragmentShader(fragShaderFile);
	glCompileShader(fragShader);
	
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &compiled);
	// Error during shader compilation
	if(compiled == 0)
	{
		glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &errLength);
		errorMSG = new char[errLength+1];	// +1 for the null terminating character
		glGetShaderInfoLog(vertShader, errLength, NULL, errorMSG);
		string temp(errorMSG);
		log << "Fragment Shader Log: \n" << temp;
		log.close();
		delete errorMSG;
		return 0;
	}
	
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);
	
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linked);
	// Error during program linking
	if(linked == 0)
	{
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &errLength);
		errorMSG = new char[errLength+1];	// +1 for the null terminating character
		glGetProgramInfoLog(shaderProgram, errLength, NULL, errorMSG);
		string temp(errorMSG);
		log << "Shader Program Log: \n" << temp;
		log.close();
		delete errorMSG;
		return 0;
	}
	
	log.close();
	return shaderProgram;
}
// Installs this shader program into the pipeline
void Shader::enable()
{
	glUseProgram(shaderProgram);
}

// Uninstalls this shader program from the pipeline
void Shader::disable()
{
	glUseProgram(0);
}

GLuint Shader::getShader() const
{
	return shaderProgram;
}

bool Shader::load(std::string &a)
{
	return true;
}