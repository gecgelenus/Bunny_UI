#ifndef SHADER_HPP
#define SHADER_HPP
#include <GL/glew.h>



class Shader{

public:
    Shader();
    ~Shader();

    void createShader(const char* shaderSource, GLenum shaderType);
    void compileShader();
    GLuint getShaderID() const;


private:
    GLuint shaderID;
    GLuint shaderType;
    const char* shaderSource;


};

#endif