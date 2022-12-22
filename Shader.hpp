#ifndef SHADER_HPP
#define SHADER_HPP


#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader{

public:
    Shader();
    ~Shader();

    void createShader(const char* shaderSource, GLenum shaderType);
    void compileShader();
    GLuint getShaderID() const;


private:
    GLuint shaderID;
    GLenum shaderType;
    const char* shaderSource;


};

#endif