#include "hardware_event.h"

bool pollHardWareEvent(HardwareEvent* hw_event)
{
    SDL_Event low_level_event = {};

    if (SDL_PollEvent(&low_level_event))
    {
        switch (low_level_event.type)
        {
            case SDL_QUIT:
                hw_event->quit = low_level_event.quit;
                break;

            case SDL_MOUSEBUTTONUP:
                hw_event->mbutton = low_level_event.button;
                break;

            case SDL_MOUSEBUTTONDOWN:
                hw_event->mbutton = low_level_event.button;
                break;

            case SDL_MOUSEMOTION:
                hw_event->mmotion = low_level_event.motion;
                break;
            
            default:
                return false;
        }
        
        hw_event->type = static_cast<HardwareEventType>(low_level_event.type);
        return true;
    }
    return false;
}