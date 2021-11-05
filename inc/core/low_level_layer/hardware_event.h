#pragma once

#include "display.h"


enum HardwareEventType
{
    QUIT = SDL_QUIT,
    
    MBUTTON_DOWN = SDL_MOUSEBUTTONUP,
    MBUTTON_UP = SDL_MOUSEBUTTONDOWN,
    
    MMOTION = SDL_MOUSEMOTION,
};

const uint32_t MBUTTON_LEFT   = SDL_BUTTON_LMASK;
const uint32_t MBUTTON_RIGHT  = SDL_BUTTON_RMASK;
const uint32_t MBUTTON_MIDDLE = SDL_BUTTON_MMASK;

using MouseMotionEvent = SDL_MouseMotionEvent;
using MouseButtonEvent = SDL_MouseButtonEvent;
using QuitEvent = SDL_QuitEvent;

union HardwareEvent
{   
    HardwareEventType type;
    
    QuitEvent quit;

    MouseButtonEvent mbutton;
    MouseMotionEvent mmotion;
};

bool pollHardWareEvent(HardwareEvent* event);