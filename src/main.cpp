#include "filled_rectangle.h"
#include "filled_circle.h"
#include "simple_text.h"
#include "graphic_frame.h"

const char* ANCIENT_STYLE_GUI[] =
{   
    // background
    nullptr, 
    
    // sides
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/left-side.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/top-side.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/right-side.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/bottom-side.png",

    // corners
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/top-left.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/top-right.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/bottom-right.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/bottom-left.png",
};

int main() 
{   
    Display display("Nam pizda");

    PixelPoint nam = {400, 400};
    Color pizda = {255, 0, 0, 255};
    FilledCircle circle(nam, pizda, 20);

    Rectangle rectangle = {40, 40, 40, 60};
    Color red = {255, 0, 0, 255};
    FilledRectangle filled_rectangle(rectangle, red);

    Color white = {255, 255, 255, 255};
    SimpleText simple_text(display,
                           "/home/locllos/Documents/Projects/VirtualArtist/res/TerminusTTF.ttf", 
                           "Hello, World!", 24, white);

    Texture texture(display, 
                    "/home/locllos/Documents/Projects/VirtualArtist/res/close.png", 
                    32, 32);

    Texture drawable_texture(display, 100, 80);
    drawable_texture.drawRectangle(&display, {0, 0, 50, 40}, {0, 0, 255, 255});
    drawable_texture.drawRectangle(&display, {55, 45, 25, 25}, {0, 0, 255, 255});
    drawable_texture.Draw(&display, {800, 800});

    Rectangle gui_area = {500, 0, 400, 300};
    GraphicFrame composite(display, gui_area, ANCIENT_STYLE_GUI, 20);

    composite.Draw(&display);

    PixelPoint texture_pos = {300, 300};
    display.fillRect({300, 300, 200, 200}, white);
    texture.Draw(&display, texture_pos);
    simple_text.Draw({100, 100});
    filled_rectangle.Draw(&display);
    circle.Draw(&display);

    display.Present();

    int test = 0;
    scanf("%d", &test);

    return 0;
}