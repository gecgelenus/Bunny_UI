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
    void setData(const std::vector<float>& data);
    void setRectangle(float x, float y, float width, float height);

private:

    unsigned int VAO;
    unsigned int VBO;
    std::vector<float> data;
    Frame frame;
    unsigned int vertex_count;



};









#endif // RECTANGLE_HPP