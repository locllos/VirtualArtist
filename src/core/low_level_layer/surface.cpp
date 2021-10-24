#include "surface.h"

Surface::Surface(int width, int height)
    : width_(width < 0 ? 0 : width)
    , height_(height < 0 ? 0 : height)
    , data_(new Color[width_ * height_])
    {}
