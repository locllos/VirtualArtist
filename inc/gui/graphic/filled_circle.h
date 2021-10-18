#include "graphic.h"

class FilledCircle : public GraphComponent
{
private:

    int display_radius_;
    float field_radius_;

public:

    FilledCircle() = default;
    FilledCircle(const Vector2<float>& coord, const Color& color, float radius);
    FilledCircle(const Color& color);

    void Draw(Display* display) override;  

    void fitToDisplay(int scale, bool is_stretchable) override;
    
    virtual ~FilledCircle() = default;
};