#include "graphic.h"
#include "../../core/low_level_layer/simple_text.h"


class Text : public GraphComponent
{
private:

    SimpleText text_;
    
    int display_font_size_;
    float field_font_size_;

public:

    Text(const Display& display, const Color& color,
         const Vector2<float>& coord, 
         const char* font_path, char* text, float font_size);

    void Draw(Display* display) override;

    void fitToDisplay(int scale, bool is_stretchable) override;
};