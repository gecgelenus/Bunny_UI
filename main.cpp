#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "Util.hpp"
#include "Drawables.hpp"



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
   

    if(!glfwInit()){
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if(!window){
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
     //init glew
    if(glewInit() != GLEW_OK){
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    

    Shader vertexShader;
    vertexShader.createShader(readShaderSource("./Shaders/vertex.shader"), GL_VERTEX_SHADER);
    vertexShader.compileShader();

    Shader fragmentShader;
    fragmentShader.createShader(readShaderSource("./Shaders/fragment.shader"), GL_FRAGMENT_SHADER);
    fragmentShader.compileShader();

    ShaderProgram shaderProgram;
    shaderProgram.attachShader(vertexShader);
    shaderProgram.attachShader(fragmentShader);
    shaderProgram.link();
    shaderProgram.use();

    Rectangle* rectangle = new Rectangle();
    rectangle->setData(vertices);


    
    
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our triangle
        rectangle->draw();
        // swap the back and front buffers
        glfwSwapBuffers(window);

        // poll for events
        glfwPollEvents();
    }





    glfwTerminate();
    return 0;
}




