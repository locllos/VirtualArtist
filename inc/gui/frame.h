#include "../core/field.h"
#include "graphic/graphic.h"
#include "../tools/list.hpp"

class AbstractFrame
{
protected:
    
    GraphComponent* graphics_;

    List<AbstractFrame*> subframes_;
    
    // coords relative to the parent frame
    FieldRectangle field_area_;

public:

    AbstractFrame()  = default;
    ~AbstractFrame() = default;
    
    // virtual void eventFeedback(/*some parametres*/) = 0;
};

class MainTitleFrame : public AbstractFrame
{
public:

    /**
     * @brief Construct a Main Title with buttons: file, image, window, help
     * 
     * @param field_area 
     */
    MainTitleFrame(const FieldRectangle& field_area);

    // virtual void eventFeedback(/*some parametres*/) = 0;

    ~MainTitleFrame();
};

class Palette : public AbstractFrame
{
public:

    /**
     * @brief Construct a Main Frame with buttons that can change thickness of paintbrush
     * 
     * @param field_area 
     */
    Palette(const FieldRectangle& field_area);

    // virtual void eventFeedback(/*some parametres*/) = 0;

    ~Palette();
};
