#include "../../../inc/gui/graphic/filled_rectangle.h"

FilledRectangle::FilledRectangle(const FieldRectangle& area, const Color& color) 
    : field_width_(area.width)
    , field_height_(area.height)
    , display_width_(int(area.width))
    , display_height_(int(area.height))
{
    color_ = color;
    coord_ = area.coord;

    pos_ = {int(coord_.x), int(coord_.y)};
}

void FilledRectangle::fitToDisplay(int scale, bool is_stretchable)
{
    if (is_stretchable)
    {
        display_width_ = scale * int(field_width_);
        display_height_ = scale * int(field_height_);

        pos_ = {scale * int(coord_.x + 0.5), scale * int(coord_.y + 0.5)};
    }
    else
    {
        display_width_ = int(field_width_);
        display_height_ = int(field_height_);

        pos_ = {int(coord_.x + 0.5), int(coord_.y + 0.5)};
    } 
}

void FilledRectangle::Draw(Display* display)
{
    display->fillRect({pos_.x, pos_.y, display_width_, display_height_}, color_);
}