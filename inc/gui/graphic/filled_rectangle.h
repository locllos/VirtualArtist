#pragma once

#include "graphic.h"
#include "../../core/field.h"


class FilledRectangle : public GraphComponent
{
private:

    int field_width_;
    int field_height_;

    int display_width_;
    int display_height_;

public:

    FilledRectangle() = default;
    FilledRectangle(const FieldRectangle& area, const Color& color);

    void fitToDisplay(int scale, bool is_stretchable) override;

    void Draw(Display* display) override;

    virtual ~FilledRectangle() = default;
};