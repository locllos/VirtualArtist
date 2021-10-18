#pragma once

#include "display.h"
#include "string.h"
#include <SDL2/SDL_ttf.h>

class SimpleText
{

private:

    char* font_path_;
    char* text_;

    int font_size_;

    Color color_;
    TTF_Font* font_;
    SDL_Texture* text_texture_;

    SDL_Renderer* renderer_;

    void initFont();

public:

    SimpleText(const Display& display, const char* font_path, char* text, int font_size, const Color& color);

    void changeFontSize(int font_size);

    void Draw(const PixelPoint& position);

    ~SimpleText();
};