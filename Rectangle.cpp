#include "Rectangle.hpp"
#include <GL/glew.h>
#include <iostream>




Rectangle::Rectangle(const Frame& frame) : frame(frame) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}

Rectangle::~Rectangle(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::draw() {
    // draw our first triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
    glBindVertexArray(0);
}

void Rectangle::setData(const std::vector<float>& data) {
    this->data = data;
    this->vertex_count = data.size() / 3;

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Rectangle::setRectangle(float x, float y, float width, float height) {
    
    

    
    if(x < 0 || y < 0 || width < 0 || height < 0){
        std::cout << "Rectangle::setRectangle: invalid arguments" << std::endl;
        return;
    }

    if(x>frame.getWidth() || y>frame.getHeight()){
        std::cout << "Rectangle::setRectangle: invalid arguments" << std::endl;
        return;
    }


    float x_coord;
    float y_coord;

    float h_arranged = height/frame.getHeight();
    float w_arranged = width/frame.getWidth();

    x_coord = 2.0f/(frame.getWidth()/x) - 1.0f;
    y_coord = 2.0f/(frame.getHeight()/y) - 1.0f;
    

    
    
    
    std::vector<float> data = {
        //first triangle
        x_coord - w_arranged, y_coord + h_arranged, 0.0f,
        x_coord - w_arranged, y_coord - h_arranged, 0.0f,
        x_coord + w_arranged,  y_coord + h_arranged, 0.0f,
        //second triangle
        x_coord + w_arranged,  y_coord + h_arranged, 0.0f,
        x_coord - w_arranged, y_coord - h_arranged, 0.0f,
        x_coord + w_arranged,  y_coord - h_arranged, 0.0f
    };


    for(int i = 0; i < data.size(); i++){
        std::cout << data[i] << " ";
        
        if(i%3 == 2)
            std::cout << std::endl;

    }

    setData(data);
}




