#pragma once

#include "graphic.h"

class DrawableTexture : public GraphicComponent
{
private:

    Texture texture_;

public:

    DrawableTexture(const Display& display,
                    const Rectangle& area);

    void Draw(Display* display) override;

    void fillColor(Display* display, const Color& color);
    void drawRectangle(Display* display, 
                       const Rectangle& rectangle, const Color& color);
    void drawLine(Display* display, 
                   const PixelPoint& first, const PixelPoint& second, 
                   const Color& color,
                   size_t thickness = 1);

    virtual ~DrawableTexture() override = default;
};