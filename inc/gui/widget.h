#pragma once

#include "hardware_event.h"
#include "graphic.h"
#include "command.h"
#include "list.hpp"

enum FEEDBACK_TYPE
{   
    // skipped means that we do not listen this event 
    SKIPPED,

    //ignored means that we listen it, but do not process
    IGNORED,
    //replied means that we listen and process it
    REPLIED,
};

class Widget
{
protected:

    Rectangle area_;

    GraphicComponent* graphics_;
    Command* command_;

    List<Widget*> subwidget_list_;
    
public:

    Widget();
    Widget(const Rectangle& area, 
           GraphicComponent* graphics, Command* command);
    
    bool isCursorWithin(const PixelPoint& position);
    void addSubWidget(Widget* subwidget);
    
    void Draw(Display* display);

    virtual FEEDBACK_TYPE eventFeedback(const HardwareEvent& hw_event);

    virtual ~Widget();
};