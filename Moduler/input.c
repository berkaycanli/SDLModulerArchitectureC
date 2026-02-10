#include "input.h"

void inputInit(Input* input)
{
    input->quit = false;
    input->keyboard = SDL_GetKeyboardState(NULL);
}

void inputUpdate(Input* input)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            input->quit = true;
    }
}

void inputClear(Input* input)
{
    input->quit = false;
}
