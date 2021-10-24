#include "../../../inc/gui/graphic/filled_rectangle.h"

FilledRectangle::FilledRectangle(const Rectangle& area, const Color& color) 
    : width_(area.width)
    , height_(area.height)
{
    color_ = color;
    pos_ = { area.x, area.y };
}

void FilledRectangle::Draw(Display* display)
{
    display->fillRect({pos_.x, pos_.y, width_, height_}, color_);
}

// void FilledRectangle::fitToDisplay(int scale, bool is_stretchable)
// {
//     if (is_stretchable)
//     {
//         display_width_ = scale * int(field_width_);
//         display_height_ = scale * int(field_height_);

//         pos_ = {scale * int(coord_.x + 0.5), scale * int(coord_.y + 0.5)};
//     }
//     else
//     {
//         display_width_ = int(field_width_);
//         display_height_ = int(field_height_);

//         pos_ = {int(coord_.x + 0.5), int(coord_.y + 0.5)};
//     } 
// }