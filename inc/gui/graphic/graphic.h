#pragma once

#include "../../core/low_level_layer/display.h"
#include "../../tools/vector.hpp"

class GraphComponent
{
protected:

    Color color_;
    
    Vector2<float> coord_;
    PixelPoint pos_;

public:

    virtual void Draw(Display* display) = 0;

    Vector2<float> coord() const {return coord_;}

    /**
     * @param scale_x greater or equal 1
     * @param scale_y greater or equal 1
    **/
    virtual void fitToDisplay(int scale, bool is_stretchable) = 0;

    friend class Field;
};


