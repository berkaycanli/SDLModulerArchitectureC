#include "timer.h"
#include <SDL2/SDL.h>

float timerGetSeconds(void) {
    // SDL_GetTicks milisaniye döndürür, saniyeye çeviriyoruz
    return SDL_GetTicks() / 1000.0f;
}