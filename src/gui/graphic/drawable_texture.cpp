#include "drawable_texture.h"

DrawableTexture::DrawableTexture(const Display& display, const Rectangle& area)
    : texture_(display, area.width, area.height)
{
    pos_ = {area.x, area.y};
}

void DrawableTexture::Draw(Display* display)
{
    texture_.Draw(display, pos_);
}

void DrawableTexture::fillColor(Display* display, const Color& color)
{
    texture_.drawRectangle(display, 
                           {0, 0, texture_.width() - 1, texture_.height() - 1}, color);
}

void DrawableTexture::drawLine(Display* display, 
                               const PixelPoint& first, const PixelPoint& second, 
                               const Color& color,
                               size_t thickness)
{
    texture_.drawLine(display, first, second, color, thickness);
}

void DrawableTexture::drawRectangle(Display* display, 
                                    const Rectangle& rectangle, const Color& color)
{
    texture_.drawRectangle(display, rectangle, color);
}

