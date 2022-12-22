#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"

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