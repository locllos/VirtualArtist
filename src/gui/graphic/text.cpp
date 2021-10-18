#include "../../../inc/gui/graphic/text.h"

Text::Text(const Display& display, const Color& color,
           const Vector2<float>& coord, 
           const char* font_path, char* text, float font_size)

    : text_(display, font_path, text, font_size, color)
    , display_font_size_(int(font_size))
    , field_font_size_(font_size)
    {
        coord_ = coord;
        pos_ = {int(coord.x), int(coord.y)};
    }


void Text::Draw(Display* display)
{
    text_.Draw(pos_);
}

void Text::fitToDisplay(int scale, bool is_stretchable)
{
    if (is_stretchable)
    {
        pos_ = {scale * int(coord_.x + 0.5), scale * int(coord_.y + 0.5)};

        display_font_size_ = scale * int(field_font_size_);
    }
    else
    {
        pos_ = {int(coord_.x + 0.5), int(coord_.y + 0.5)};

        display_font_size_ = int(field_font_size_);
    }
    text_.changeFontSize(display_font_size_);
}
