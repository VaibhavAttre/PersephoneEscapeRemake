#pragma once
#include <string>
#include <GL/glew.h>
#include "Errors.h"

class GLSLProgram
{

public:
	GLSLProgram();
	~GLSLProgram();

	void compileShaders(std::string& vertexShaderFilePath, std::string& fragmentShaderFilePath);
	void linkShaders();

private:

	GLuint _programID;
	GLuint _vertexShaderID;
	GLuint _fragmentShaderID;
};

