#pragma once

#include "graphic.h"
#include "field.h"


class FilledRectangle : public GraphicComponent
{
private:

    int width_;
    int height_;

    Color color_;    

public:

    FilledRectangle() = default;
    FilledRectangle(const Rectangle& area, const Color& color);

    void Draw(Display* display) override;

    virtual ~FilledRectangle() = default;
};