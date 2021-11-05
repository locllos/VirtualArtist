#include "graphic_frame.h"

GraphicFrame::GraphicFrame(const Display& display, 
                           const Rectangle& area, const char* sprite_paths[], int sprite_scale)
    : width_(area.width)
    , height_(area.height)
    , sprite_scale_(sprite_scale)
    , is_ready_to_draw_(true)
    , textures_(nullptr, AMOUNT_PARTS)
{
    pos_ = {area.x, area.y};
    
    for (int i = LEFT_SIDE; i < AMOUNT_PARTS; ++i)
    {
        initCompositePart(display, static_cast<COMPOSITE_TYPE>(i), sprite_paths[i]);
    }
    if (sprite_paths[BACKGROUND] != nullptr)
    {
        if (sprite_paths[BACKGROUND][0] == '\0')
        {
            textures_[BACKGROUND] = new Texture(display, width_, height_);
        }
        else
        {
            textures_[BACKGROUND] = new Texture(display, 
                                                sprite_paths[BACKGROUND], width_, height_);
        }
    }
}

void GraphicFrame::initCompositePart(const Display& display, COMPOSITE_TYPE type,
                                        const char* sprite_path)
{   
    int sprite_width = width_ / sprite_scale_;
    int sprite_height = height_ / sprite_scale_;

    textures_[type] = new Texture(display, sprite_path, sprite_width, sprite_height);
}

void GraphicFrame::drawSides(Display* display)
{
    // left side
    PixelPoint current = pos_;
    while (current.y < pos_.y + height_ - textures_[LEFT_SIDE]->height())
    {
        textures_[LEFT_SIDE]->Draw(display, current);
        
        current.y += textures_[LEFT_SIDE]->height();        
    }
    // top side 
    current = pos_;
    while (current.x < pos_.x + width_ - textures_[TOP_SIDE]->width())
    {
        textures_[TOP_SIDE]->Draw(display, current);

        current.x += textures_[TOP_SIDE]->width();
    }
    // right side
    current = {pos_.x + width_ - textures_[RIGHT_SIDE]->width(), pos_.y};
    while (current.y < pos_.y + height_ - textures_[RIGHT_SIDE]->height())
    {
        textures_[RIGHT_SIDE]->Draw(display, current);

        current.y += textures_[RIGHT_SIDE]->height();
    }
    // bottom side
    current = {pos_.x, pos_.y + height_ - textures_[BOTTOM_SIDE]->height()};
    while (current.x < pos_.x + width_ - textures_[TOP_SIDE]->width())
    {
        textures_[TOP_SIDE]->Draw(display, current);

        current.x += textures_[TOP_SIDE]->width();
    }
}

void GraphicFrame::drawCorners(Display* display)
{
    PixelPoint current = pos_;
    textures_[TOP_LEFT_CORNER]->Draw(display, current);

    current = {pos_.x + width_ - textures_[TOP_RIGHT_CORNER]->width(), 
               pos_.y};
    textures_[TOP_RIGHT_CORNER]->Draw(display, current);

    current = {pos_.x + width_  - textures_[BOTTOM_RIGHT_CORNER]->width(), 
               pos_.y + height_ - textures_[BOTTOM_RIGHT_CORNER]->height()};
    textures_[BOTTOM_RIGHT_CORNER]->Draw(display, current);


    current = {pos_.x, 
               pos_.y + height_ - textures_[BOTTOM_LEFT_CORNER]->height()};
    textures_[BOTTOM_LEFT_CORNER]->Draw(display, current);
}

void GraphicFrame::Draw(Display* display)
{
    if (textures_[BACKGROUND] != nullptr) 
    {
        textures_[BACKGROUND]->Draw(display, pos_);
    }
    drawSides(display);
    drawCorners(display);
}

GraphicFrame::~GraphicFrame()
{
    for (int i = 0; i < AMOUNT_PARTS; ++i)
    {
        delete textures_[i];
    }
}