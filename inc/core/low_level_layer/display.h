#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <assert.h>

#include <iostream>
#include <stdint.h>

using std::cin;
using std::cout;
using std::endl;

class Texture;

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

    void Dump();
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

const int AUTO_WIDTH = -1;
const int AUTO_HEIGHT = -1;

const char PNG_FORMAT[] = "png";
const char JPG_FORMAT[] = "jpg";
const char BMP_FORMAT[] = "bmp";

const size_t IMG_INIT_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG;


/**
 * @brief class display is low level layer between sdl and high level code
 * 
 */
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
            size_t width = 1600, size_t height = 900,
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


class Texture
{
private:

    int width_;
    int height_;
    
    SDL_Texture* native_texture_;


public:

    Texture();
    Texture(const Display& display, int width, int height, 
            uint32_t format = SDL_PIXELFORMAT_RGBA8888, int access = SDL_TEXTUREACCESS_TARGET);
    Texture(const Display& display, 
            const char* picture_path, int width, int height);

    void Draw(Display* display, const PixelPoint& position);
    void drawPoint(Display* display, const PixelPoint& point, const Color& color);
    void drawLine(Display* display, 
                  const PixelPoint& first, const PixelPoint& second, const Color& color,
                  size_t thickness = 1);

    void drawRectangle(Display* display, const Rectangle& rectangle, const Color& color);
    
    int width() const;
    int height() const;

    bool isInitialized();

    ~Texture();
};