#ifndef FRAME_HPP
#define FRAME_HPP
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "ShaderProgram.hpp"

class Frame
{
public:
    Frame(std::string name, int width, int height);
    ~Frame();
    
    GLuint getShaderProgram() const;
    GLFWwindow* getWindow() const;




private:
    GLFWwindow* window;
    std::string name;
    int width;
    int height;    

    GLuint programID;


};








#endif // FRAME_HPP