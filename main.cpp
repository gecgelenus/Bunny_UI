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
    

    Rectangle* rectangle = new Rectangle(frame);
    rectangle->setRectangle(400, 300, 100, 100);

    Rectangle* rectangle2 = new Rectangle(frame);
    rectangle2->setRectangle(200, 300, 50, 200);


    frame.addDrawable(rectangle);
    frame.addDrawable(rectangle2);
    frame.setClearColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    
    
    while(!glfwWindowShouldClose(frame.getWindow())){
     frame.render();   
    }





    glfwTerminate();
    return 0;
}




