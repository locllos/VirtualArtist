#include "../../../inc/gui/graphic/filled_circle.h"

FilledCircle::FilledCircle(const Vector2<float>& coord, const Color& color, float radius) : field_radius_(radius), display_radius_(int(radius)) 
{
    coord_ = coord;
    color_ = color;

    pos_ = {int(coord_.x), int(coord_.y)};
};

FilledCircle::FilledCircle(const Color& color) : field_radius_(0) {color_ = color; coord_ = {}; };

void FilledCircle::fitToDisplay(int scale, bool is_stretchable)
{
    if (is_stretchable)
    {
        display_radius_ = scale * int(field_radius_);
        pos_ = {scale * int(coord_.x + 0.5), scale * int(coord_.y + 0.5)};
    }
    else
    {
        display_radius_ = int(field_radius_);
        pos_ = {int(coord_.x + 0.5), int(coord_.y + 0.5)};
    } 
}

void FilledCircle::Draw(Display* display)
{   
    PixelPoint position = pos_;
    PixelPoint point = {position.x - display_radius_, position.y - display_radius_};

    for (; point.x < position.x; ++point.x)
    {   
        for (; point.y < position.y; ++point.y)
        {   
            PixelPoint result = position - point;
            if (result.x * result.x + result.y * result.y <= display_radius_ * display_radius_)
            {   
                display->drawPoint(point);
                display->drawPoint({point.x, point.y + 2 * result.y - 1});
                display->drawPoint({point.x + 2 * result.x - 1, point.y});
                display->drawPoint({point.x + 2 * result.x - 1, point.y + 2 * result.y - 1});
            } 
        }
        point.y = position.y - display_radius_;
    }
}
