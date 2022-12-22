#include "Shader.hpp"
#include <iostream>


Shader::Shader()
{
}

Shader::~Shader()
{
    glDeleteShader(shaderID);
}

void Shader::createShader(const char* shaderSource, GLenum shaderType)
{
    this->shaderSource = shaderSource;
    this->shaderType = shaderType;
    shaderID = glCreateShader(shaderType);
}

void Shader::compileShader()
{
    glShaderSource(shaderID, 1, &shaderSource, NULL);
    glCompileShader(shaderID);
    GLint status;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        GLint infoLogLength;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shaderID, infoLogLength, NULL, strInfoLog);
        const char* strShaderType = NULL;
        std::cout << "Compile failure in shader: " << strInfoLog << std::endl;
        delete[] strInfoLog;
    }
}

GLuint Shader::getShaderID() const
{
    return shaderID;
}



