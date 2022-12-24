#include "Rectangle.hpp"
#include <GL/glew.h>
#include <iostream>




Rectangle::Rectangle(const Frame& frame) : frame(frame) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
}

Rectangle::~Rectangle(){
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::draw() {
    // draw our first triangle
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Rectangle::setData(const std::vector<float>& data, const std::vector<unsigned int>& indices) {
    this->data = data;
    this->indices = indices;
    this->vertex_count = data.size() / 3;

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);


    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
    

    
    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 1, 3
    };
    
    std::vector<float> data = {
        x_coord - w_arranged, y_coord + h_arranged, 0.0f, // 1
        x_coord - w_arranged, y_coord - h_arranged, 0.0f, // 2
        x_coord + w_arranged,  y_coord + h_arranged, 0.0f, // 3
        x_coord + w_arranged,  y_coord - h_arranged, 0.0f // 4
    };


    setData(data, indices);
}




