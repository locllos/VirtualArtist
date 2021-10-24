#include "filled_circle.h"

FilledCircle::FilledCircle(const PixelPoint& pos, const Color& color, int radius) 
            : radius_(radius)
{
    color_ = color;
    pos_ = pos;
};

FilledCircle::FilledCircle(const Color& color) 
        : radius_(0) 
{
    color_ = color; 
    pos_ = {}; 
}


void FilledCircle::Draw(Display* display)
{   
    Color old_color = display->getColor();
    display->setColor(color_);

    PixelPoint point = {pos_.x - radius_, pos_.y - radius_};

    for (; point.x < pos_.x; ++point.x)
    {   
        for (; point.y < pos_.y; ++point.y)
        {   
            PixelPoint result = pos_ - point;
            if (result.x * result.x + result.y * result.y <= radius_ * radius_)
            {   
                display->drawPoint(point);
                display->drawPoint({point.x, point.y + 2 * result.y - 1});
                display->drawPoint({point.x + 2 * result.x - 1, point.y});
                display->drawPoint({point.x + 2 * result.x - 1, point.y + 2 * result.y - 1});
            } 
        }
        point.y = pos_.y - radius_;
    }
    
    display->setColor(old_color);
}

// void FilledCircle::fitToDisplay(int scale, bool is_stretchable)
// {
//     if (is_stretchable)
//     {
//         display_radius_ = scale * int(field_radius_);
//         pos_ = {scale * int(coord_.x + 0.5), scale * int(coord_.y + 0.5)};
//     }
//     else
//     {
//         display_radius_ = int(field_radius_);
//         pos_ = {int(coord_.x + 0.5), int(coord_.y + 0.5)};
//     } 
// }