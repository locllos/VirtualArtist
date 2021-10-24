#pragma once
// does not use
#include "display.h"
#include "graphic.h"
#include "vector.hpp"

struct FieldRectangle
{
    float width;
    float height;

    Vector2<float> coord;

    FieldRectangle(const FieldRectangle& other);
};

// always begins at (0, 0)
class Field
{
private:

    Display* display_;

    int width_;
    int height_;

    int scale;

    bool is_stretchable_;

public:

    Field(Display* display, int width, int height, bool is_stretchable = true);

    void size(int width, int height);

    int width() const;
    int height() const;

    void DrawGraphComponent(GraphicComponent* graph);

    ~Field() = default;
};