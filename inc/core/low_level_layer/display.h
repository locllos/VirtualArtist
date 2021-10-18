#pragma once

#include <SDL2/SDL.h>
#include <assert.h>

struct Color
{   
    Color() = default;
    Color(uint8_t red,  uint8_t green, uint8_t blue, uint8_t alpha);

    void decreaseRGB(uint8_t value);
    void increaseRGB(uint8_t value);

    uint8_t red;
    uint8_t green;
    uint8_t blue;

    uint8_t alpha;
};

Color getRandomColor();

const Color CURRENT_COLOR = {0, 0, 0, 0};

struct PixelPoint
{
    int x;
    int y;

    PixelPoint Add(int x, int y);

    PixelPoint operator+(const PixelPoint& rhs_point);
    PixelPoint operator-(const PixelPoint& rhs_point);
    const PixelPoint& operator=(const PixelPoint& rhs_point);

};


struct MouseState
{
    PixelPoint position;

    int32_t status;

    bool isClickedLeftButton() const;
    bool isClickedMiddleButton() const;
    bool isClickedRightButton() const;
};  


struct Pixel
{
    Color color;
    PixelPoint coord;
};

struct Rectangle
{
    int x;
    int y;

    int width;
    int height;

    bool isWithin(const PixelPoint& point) const;
};

bool areColorsEqual(const Color& color_a, const Color& color_b);

Color     convertSDLColorToDefault(const SDL_Color& sdl_color);
SDL_Color convertDefaultColorToSDL(const Color& color);

Rectangle convertSDLRectangleToDefault(const SDL_Rect& sdl_rect);
SDL_Rect  convertDefaultRectangleToSDL(const Rectangle& sdl_rect);

void Delay(int time);

class Display
{
private:

    SDL_Window* window_;
    SDL_Renderer* renderer_;

    int width_;
    int height_;

    void drawBoldLine(PixelPoint first, PixelPoint second, size_t thickness);

public:

    Display() = delete;
    
    Display(const char* title, 
            size_t width = 1024, size_t height = 768,
            size_t x_pos =  SDL_WINDOWPOS_CENTERED, size_t y_pos =  SDL_WINDOWPOS_CENTERED,
            uint32_t window_flags = 0, uint32_t renderer_flags = 0);

    SDL_Window* window() const;
    SDL_Renderer* renderer() const;

    int width() const;
    int height() const;

    void getWindowSize(int* width, int* height) const;

    void Clear();
    void Present();

    Color getColor() const;
    void  setColor(const Color& color);

    void drawLine(const PixelPoint& first, const PixelPoint& second, Color color = CURRENT_COLOR, size_t thickness = 1);
    
    void drawPoint(const PixelPoint& point, Color = CURRENT_COLOR);
    
    void fillRect(const Rectangle& rect, Color color = CURRENT_COLOR);
    void clipRect(const Rectangle& rect);
    void unClipRect();

    bool isWithinWindow(const PixelPoint& point) const;

    MouseState getMouseState() const;

    ~Display();
};
