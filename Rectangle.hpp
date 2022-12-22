#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Draw_interfaces.hpp"
#include "Util.hpp"
#include <vector>

class Rectangle : public Drawable {

public:
    Rectangle();
    ~Rectangle();
    void draw() override;
    void setData(const std::vector<float>& data);

private:

    unsigned int VAO;
    unsigned int VBO;
    std::vector<float> data;
    unsigned int vertex_count;



};









#endif // RECTANGLE_HPP