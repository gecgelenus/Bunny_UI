#include "Frame.hpp"
#include "Util.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"

Frame::Frame(std::string name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;

    if(!glfwInit()){
        std::cout << "Failed to initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if(!window){
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    //init glew
    if(glewInit() != GLEW_OK){
        std::cout << "Failed to initialize GLEW" << std::endl;
        return;
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

    GLuint programID = shaderProgram.getProgramID();
}

Frame::~Frame()
{
    glfwTerminate();
}

GLuint Frame::getShaderProgram() const
{
    return programID;
}

GLFWwindow* Frame::getWindow() const
{
    return window;
}


