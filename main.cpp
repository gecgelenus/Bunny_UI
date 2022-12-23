#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Util.hpp"
#include "Drawables.hpp"
#include "Frame.hpp"


// vertex data for our triangle
const std::vector<GLfloat> vertices = {
    //first triangle
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f,  0.5f, 0.0f,
    //second triangle
    -0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.5f,  -0.5f, 0.0f
};





int main(){
   

    Frame frame("Hello World", 800, 600);
    

    Rectangle* rectangle = new Rectangle();
    rectangle->setData(vertices);

    
    
    
    while(!glfwWindowShouldClose(frame.getWindow())){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our triangle
        rectangle->draw();
        // swap the back and front buffers
        glfwSwapBuffers(frame.getWindow());

        // poll for events
        glfwPollEvents();
    }





    glfwTerminate();
    return 0;
}




