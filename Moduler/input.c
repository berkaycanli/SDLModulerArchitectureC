#include "input.h"
#include <SDL2/SDL.h>


void inputInit(Input* input)
{
    input->quit  = false;
    input->moveX = 0;
    input->moveY = 0;
    input->action = false;
}


void inputUpdate(Input* input)
{
    SDL_Event e;
    const Uint8* kb = SDL_GetKeyboardState(NULL);

    input->moveX = 0;
    input->moveY = 0;
    input->action = false;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            input->quit = true;
    }

    if (kb[SDL_SCANCODE_ESCAPE])input->quit = true;

    if (kb[SDL_SCANCODE_D]) input->moveX = 1;
    if (kb[SDL_SCANCODE_A]) input->moveX = -1;
    if (kb[SDL_SCANCODE_W]) input->moveY = -1;
    if (kb[SDL_SCANCODE_S]) input->moveY = 1;

    if (kb[SDL_SCANCODE_SPACE])
        input->action = true;
}


void inputClear(Input* input)
{
    input->quit = false;
}
