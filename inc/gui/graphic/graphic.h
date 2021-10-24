#pragma once

#include "display.h"
#include "vector.hpp"

class GraphicComponent
{
protected:
    
    PixelPoint pos_;

public:

    virtual void Draw(Display* display) = 0;

    PixelPoint pos() const {return pos_;}

    virtual ~GraphicComponent() = default;
};


