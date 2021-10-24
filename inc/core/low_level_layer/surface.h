#include "display.h"
#include "square_bracket_layer.hpp"

// I thought I need it, but not
class Surface
{
private:

    int width_;
    int height_;
    
    SquareBracketsLayer<Color> data_;


public:

    Surface(int width, int height);

    SquareBracketsLayer<Color>& operator[](int idx);

    ~Surface();

};
