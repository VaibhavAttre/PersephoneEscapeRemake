#include "GLSLProgram.h"
#include <fstream>
#include <vector>

GLSLProgram::GLSLProgram() : _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{
	//
}

GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::compileShaders(std::string& vertexShaderFilePath, std::string& fragmentShaderFilePath)
{
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0) {
		fatalError("VS failed to be created");
	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0) {
		fatalError("FS failed to be created");
	}

	std::ifstream vertexFile(vertexShaderFilePath);
	if (vertexFile.fail()) {
		fatalError("Failed to open" + vertexShaderFilePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(vertexFile, line)) {
		fileContents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = fileContents.c_str();
	glShaderSource(_vertexShaderID, 1, &contentsPtr, nullptr);
	glCompileShader(_vertexShaderID);
	GLint success = 0;
	glGetShaderiv(_vertexShaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {

		GLint maxLength = 0;
		glGetShaderiv(_vertexShaderID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(_vertexShaderID, maxLength, &maxLength, &errorLog[0]);
		glDeleteShader(_vertexShaderID);
		fatalError("Sahder failed to compile");
		return;
	}
}

void GLSLProgram::linkShaders()
{
}
