#include "field.h"

FieldRectangle::FieldRectangle(const FieldRectangle& other)
{
    width = other.width;
    height = other.height;

    coord = other.coord;
}

Field::Field(Display* display, int width, int height, bool is_stretchable) 
    : display_(display)
    , width_(width)
    , height_(height)
    , is_stretchable_(is_stretchable) 
{   
    
    int scale_x = display->width() / width_;
    int scale_y = display->height() / height_,

    scale = scale_x > scale_y ? scale_y : scale_x;
}

void Field::size(int width, int height)
{
    width_ = width;
    height_ = height;
}

int Field::width() const
{
    return width_;
}

int Field::height() const
{
    return height_;
}

void Field::DrawGraphComponent(GraphicComponent* graph)
{
    graph->Draw(display_);
}