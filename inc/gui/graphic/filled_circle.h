#pragma once

#include "graphic.h"


class FilledCircle : public GraphicComponent
{
private:

    Color color_;

    int radius_;

public:

    FilledCircle() = default;
    FilledCircle(const PixelPoint& pos, const Color& color, int radius);
    FilledCircle(const Color& color);

    void Draw(Display* display) override;
};