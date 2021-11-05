#include "widget.h"

Widget::Widget()
    : area_({})
    , graphics_(nullptr)
    , command_(nullptr)
    , subwidget_list_()
    {}

Widget::Widget(const Rectangle& area, 
               GraphicComponent* graphics, Command* command)
    : area_(area)
    , graphics_(graphics)
    , command_(command)
    , subwidget_list_()
    {}

bool Widget::isCursorWithin(const PixelPoint& position)
{
    return area_.isWithin(position);
}

void Widget::addSubWidget(Widget* subwidget)
{
    subwidget_list_.Append(subwidget);
}

void Widget::Draw(Display* display)
{   
    if (graphics_ != nullptr)
    {
        graphics_->Draw(display);
    }
    

    Node<Widget*>* current = subwidget_list_.head();
    while (current != nullptr)
    {
        current->value->Draw(display);
        current = current->next;
    }    
    
}

FEEDBACK_TYPE Widget::eventFeedback(const HardwareEvent& hw_event)
{   
    PixelPoint cursor_pos = { hw_event.mmotion.x, hw_event.mmotion.y };
    Node<Widget*>* current = subwidget_list_.head();
    while (current != nullptr)
    {
        if (current->value->isCursorWithin(cursor_pos))
        {   
            FEEDBACK_TYPE feedback_type = current->value->eventFeedback(hw_event);

            if (feedback_type == REPLIED)
            {
                subwidget_list_.makeHead(current);
            }
            else if (command_ != nullptr)
            {
                command_->Execute();
                feedback_type = REPLIED;
            }
            return feedback_type;
        }
        current = current->next;
    }
    return SKIPPED;
};

Widget::~Widget()
{
    delete command_;
    delete graphics_;

    Node<Widget*>* current = subwidget_list_.head();
    while (current != nullptr)
    {
        delete current->value;

        current = current->next;
    }
}