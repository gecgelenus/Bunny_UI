#ifndef DRAW_INTERFACES_HPP
#define DRAW_INTERFACES_HPP
#include "Util.hpp"
#include "ShaderProgram.hpp"

class Drawable {

public:

    Drawable() = default;

    virtual void draw() = 0;


    

};

#endif // DRAW_INTERFACES_HPP