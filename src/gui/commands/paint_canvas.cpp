#include "paint_canvas.h"

PaintCanvas::PaintCanvas(const PixelPoint& origin_point, Display* display,
                         PaintBrush* paint_brush, DrawableTexture* texture)
    : origin_pos_(origin_point)
    , last_pos_({-1, -1})
    , paint_brush_(paint_brush)
    , texture_(texture)
    , display_(display)
    {}


void PaintCanvas::Execute()
{   
    PixelPoint current_pos = {};

    if (!paint_brush_->is_active)
    {
        last_pos_ = {-1, -1};
        return;
    }

    if (last_pos_.x == -1)
    {
        current_pos = paint_brush_->cursor_position - 
                      origin_pos_ - 
                      PixelPoint({paint_brush_->thickness / 2, 
                                  paint_brush_->thickness / 2});
        
        Rectangle thick_point = {current_pos.x, current_pos.y, 
                                paint_brush_->thickness, paint_brush_->thickness};

        texture_->drawRectangle(display_, thick_point, paint_brush_->color);
    }
    else
    {
        current_pos = paint_brush_->cursor_position - origin_pos_;
        texture_->drawLine(display_, last_pos_, current_pos, 
                           paint_brush_->color, paint_brush_->thickness);
    }
    last_pos_ = current_pos;   
}