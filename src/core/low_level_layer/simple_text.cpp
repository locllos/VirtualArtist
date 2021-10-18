#include "../../inc/core/low_level_layer/simple_text.h"

SimpleText::SimpleText(const Display& display, const char* font_path, char* text, int font_size, const Color& color)
    : font_size_(font_size)
    , font_(nullptr)
    , text_texture_(nullptr)
    , renderer_(display.renderer())
{   
    color_ = color;

    font_path_ = new char[strlen(font_path)];
    strcpy(font_path_, font_path);

    text_ = new char[strlen(text)];
    strcpy(text_, text);
}

void SimpleText::initFont()
{   
    if (font_ != nullptr) return;
    
    font_ = TTF_OpenFont(font_path_, font_size_);

    SDL_Surface* text_surface = TTF_RenderText_Blended(font_, text_, convertDefaultColorToSDL(color_));

    text_texture_ = SDL_CreateTextureFromSurface(renderer_, text_surface);

    SDL_FreeSurface(text_surface);
}

void SimpleText::changeFontSize(int font_size)
{
    if (font_size_ == font_size) return;

    font_size_ = font_size;

    if (font_ != nullptr) 
    {
        TTF_CloseFont(font_);
        SDL_DestroyTexture(text_texture_);

        font_ = nullptr;
        text_texture_ = nullptr;
    }

    initFont();
}

void SimpleText::Draw(const PixelPoint& point)
{   
    if (font_ == nullptr) initFont();

    int text_width = 0;
    int text_height = 0;

    SDL_QueryTexture(text_texture_, nullptr, nullptr, &text_width, &text_height);

    SDL_Rect texture_rect = {point.x, point.y, text_width, text_height};
    SDL_RenderCopy(renderer_, text_texture_, nullptr, &texture_rect);
}

SimpleText::~SimpleText()
{   
    delete[] font_path_;
    delete[] text_;

    TTF_CloseFont(font_);
    SDL_DestroyTexture(text_texture_);
}