#include "graphic.h"
#include "array.hpp"

const int DEFAULT_SPRITE_SCALE = 10;

enum COMPOSITE_TYPE
{
    BACKGROUND = 0,

    LEFT_SIDE,
    TOP_SIDE,
    RIGHT_SIDE,
    BOTTOM_SIDE,

    TOP_LEFT_CORNER,
    TOP_RIGHT_CORNER,
    BOTTOM_RIGHT_CORNER,
    BOTTOM_LEFT_CORNER,

    AMOUNT_PARTS,
};

class GraphicFrame : public GraphicComponent
{
private:

    int width_;
    int height_;

    int sprite_scale_;

    bool is_ready_to_draw_;

    // first texture is a background texture, 
    // if sprite path is nullptr it creates drawable background texture
    //
    // first four textures is left, top, right, bottom texture sides
    // second four textures are top-left, top-right, 
    //                         bottom-right, bottom-left texture corners
    Array<Texture*> textures_;

private:

    void drawSides(Display* display);
    void drawCorners(Display* display);

public:

    /**
     * @brief sprite_paths contains 9 strings, where second 8 string necessarily non-empty, 
     *        first can be: (1) empty, this means that foreground will be drawable;
     *                      (2) nullptr, this means that foreground will not draw
     * @param area 
     * @param sprite_paths 
     * @param sprite_scale 
     */
    GraphicFrame(const Display& display, const Rectangle& area, 
                     const char* sprite_paths[], int sprite_scale = DEFAULT_SPRITE_SCALE);

    void initCompositePart(const Display& display, COMPOSITE_TYPE type,
                          const char* sprite_path);
    
    void Draw(Display* display) override;

    virtual ~GraphicFrame() override;
};