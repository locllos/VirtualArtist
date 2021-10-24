#include "graphic.h"
#include "simple_text.h"


class Text : public GraphicComponent
{
private:

    Color color_;
    
    SimpleText text_;

public:

    Text(const Display& display, const Color& color,
         const PixelPoint& pos, 
         const char* font_path, char* text, float font_size);

    void Draw(Display* display) override;
};