#pragma once

#include "../frame.h"
#include "command.h"

class AbstractButton : public AbstractFrame
{
protected:

    Command* execute_;

public:

    virtual void Action(const MouseState& status) = 0;

    virtual ~AbstractButton();
};

class IlluminatedButton : public AbstractButton
{
private:

    Color new_color_;
    bool color_changed;
    size_t illuminated_factor_;
    int decrease_factor_;
    int smooth_fading_factor_;

    void actionSmoothFading();
    void actionClick();

public:

    IlluminatedButton(Command* command, GraphComponent* graph, size_t illum_factor = 50);

    void Action(const MouseState& status) override;
};




















/* Через наследование, без выделения памяти, мне не понравилось как это выглядит
class IButton
{
protected:

    Command* execute_;

public:

    virtual void Action(const MouseState& status) = 0;

    virtual ~IButton();
};

class IlluminatedButton : public IButton, public FilledCircle
{
private:

    Color new_color_;
    bool color_changed;
    size_t illuminated_factor_;
    int decrease_factor_;
    int smooth_fading_factor_;

    void actionSmoothFading();
    void actionClick();

public:

    IlluminatedButton(/*some parametres*//*/);

    void Action(const MouseState& status) override;
};
*/


