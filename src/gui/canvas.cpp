#include "canvas.h"

Canvas::Canvas(const Rectangle& area, Display* display,
               DrawableTexture* texture, Command* command, PaintBrush* paint_brush)
    : Widget(area, static_cast<GraphicComponent*>(texture), command)
    , paint_brush_(paint_brush)
{
    texture->fillColor(display, WHITE);
}

FEEDBACK_TYPE Canvas::eventFeedback(const HardwareEvent& hw_event)
{   
    if (hw_event.type == MBUTTON_UP)
    {
        paint_brush_->is_active = true;
    }
    else if (hw_event.type == MBUTTON_DOWN)
    {
        paint_brush_->is_active = false;
    }

    if (hw_event.type == MMOTION)
    {
        paint_brush_->cursor_position = {hw_event.mbutton.x, hw_event.mbutton.y};
        command_->Execute();

        return static_cast<FEEDBACK_TYPE>(REPLIED);
    }
    return static_cast<FEEDBACK_TYPE>(IGNORED);
}
