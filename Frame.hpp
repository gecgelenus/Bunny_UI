#ifndef FRAME_HPP
#define FRAME_HPP
#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Draw_interfaces.hpp"


class Frame
{
public:
    Frame(std::string name, int width, int height);
    ~Frame();
    
    uint getShaderProgram() const;
    GLFWwindow* getWindow() const;

    void addDrawable(Drawable* drawable);
    void removeDrawable(Drawable* drawable);

    void render();
    void setClearColor(glm::vec4 color);

    int getWidth();
    int getHeight();


private:
    GLFWwindow* window;

    std::string name;    
    int width;
    int height;    

    std::vector<Drawable*> drawables;

    glm::vec4 clearColor;

    uint programID;


};








#endif // FRAME_HPP