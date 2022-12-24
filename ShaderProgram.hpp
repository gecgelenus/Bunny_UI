#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP
#include "Shader.hpp"
#include <GL/glew.h>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();

    void attachShader(Shader shader);
    void link();
    void use();

    GLuint getProgramID() const;


private:
    GLuint programID;
    GLuint vertexShaderID;
    GLuint fragmentShaderID;



};
#endif