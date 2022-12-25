#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Draw_interfaces.hpp"
#include "Frame.hpp"
#include <vector>

class Rectangle : public Drawable {

public:
    Rectangle(const Frame& frame);
    ~Rectangle();
    void draw() override;
    void setData(const std::vector<float>& data, const std::vector<unsigned int>& indices);
    void setRectangle(float x, float y, float width, float height);
    void setColor(glm::vec4 color);

private:

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    std::vector<float> data;
    glm::vec4 color;
    std::vector<unsigned int> indices;
    Frame frame;
    unsigned int vertex_count;



};









#endif // RECTANGLE_HPP