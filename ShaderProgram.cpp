#include "ShaderProgram.hpp"
#include <iostream>

ShaderProgram::ShaderProgram()
{
    programID = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(programID);
}


void ShaderProgram::attachShader(Shader shader)
{
    glAttachShader(programID, shader.getShaderID());
}

void ShaderProgram::link()
{
    glLinkProgram(programID);
    GLint status;
    glGetProgramiv(programID, GL_LINK_STATUS, &status);
    if(status == GL_FALSE){
        GLint infoLogLength;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(programID, infoLogLength, NULL, strInfoLog);
        std::cout << "Linker failure: " << strInfoLog << std::endl;
        delete[] strInfoLog;
    }
}


void ShaderProgram::use()
{
    glUseProgram(programID);
}

GLuint ShaderProgram::getProgramID() const
{
    return programID;
}


