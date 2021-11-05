#include "command.h"
#include "canvas.h"

class PaintCanvas : public Command
{
private:

    PixelPoint origin_pos_;
    PixelPoint last_pos_;
    
    PaintBrush* paint_brush_;

    DrawableTexture* texture_;
    Display* display_;

public:

    PaintCanvas() = delete;
    PaintCanvas(const PixelPoint& origin_point, Display* display,
                PaintBrush* paint_brush, DrawableTexture* texture);
    
    void Execute() override;

    virtual ~PaintCanvas() override = default; 
};