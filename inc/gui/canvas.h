#pragma once

#include "widget.h"
#include "drawable_texture.h"

const Color WHITE = {255, 255, 255, 255};

struct PaintBrush
{
    PixelPoint cursor_position;

    Color color;
    int thickness;

    bool is_active;
};


class Canvas : public Widget
{
private:

    PaintBrush* paint_brush_;

public:

    Canvas() = delete;
    Canvas(const Rectangle& area, Display* display,
           DrawableTexture* texture, Command* command, PaintBrush* paint_brush);

    FEEDBACK_TYPE eventFeedback(const HardwareEvent& hw_event) override;

    ~Canvas() override = default;
};
