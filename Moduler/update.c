#include "update.h"
#include <SDL2/SDL.h>

void updateGame(Engine* engine, float dt)
{
    (void)dt; // şimdilik kullanılmıyor

    // ESC ile çık
    if (engine->input.keyboard[SDL_SCANCODE_ESCAPE])
    {
        engine->running = false;
    }
}
