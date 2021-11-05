#include "canvas.h"
#include "graphic_frame.h"
#include "paint_canvas.h"

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

const char* SIMPLE_STYLE_GUI[] =
{
    nullptr,

    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
    "/home/locllos/Documents/Projects/VirtualArtist/res/gui/title_theme.png",
};

int main()
{   
    Display display("fucked up");
    
    PaintBrush paint_brush = {{0, 0}, {0, 255, 0, 255}, 5, false};
    Rectangle area = {50 + 26, 50 + 20, 520 - 50 - 2, 400 - 50 + 10};
    DrawableTexture* texture = new DrawableTexture(display, area);
    Command* command = new PaintCanvas(texture->pos(), &display, &paint_brush, texture);
    GraphicFrame* frame = new GraphicFrame(display, {50, 50, 520, 400}, SIMPLE_STYLE_GUI, 20);

    Widget canvas_frame({50, 50, 520, 400}, frame, nullptr);
    Canvas canvas(area, &display, texture, command, &paint_brush);

    canvas_frame.addSubWidget(&canvas);

    HardwareEvent hw_event = {};

    bool is_closed = false;
    canvas_frame.Draw(&display);
    display.Present();
    while (!is_closed)
    {
        while (pollHardWareEvent(&hw_event))
        {   
            if (canvas_frame.eventFeedback(hw_event) == REPLIED)
            {
                canvas_frame.Draw(&display);
                display.Present();
                
                cout << "replied";
            }
            else
            {
                cout << "ignored";
            }
            cout << endl;
        }
    }

    return 0;
}

/*
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
*/