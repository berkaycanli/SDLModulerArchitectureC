#include "input.h"
#include "config.h"
#include <SDL2/SDL.h>

void inputInit(Input* input) {
    input->quit = false;
    input->moveX = 0;
    input->moveY = 0;
    input->action = false;
}

void inputUpdate(Input* input) {
    SDL_Event e;
    const Uint8* kb = SDL_GetKeyboardState(NULL);

    input->moveX = 0;
    input->moveY = 0;
    input->action = false;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) input->quit = true;
    }

    if (kb[KEY_EXIT]) input->quit = true;
    if (kb[KEY_RIGHT]) input->moveX = 1;
    if (kb[KEY_LEFT])  input->moveX = -1;
    if (kb[KEY_UP])    input->moveY = -1;
    if (kb[KEY_DOWN])  input->moveY = 1;
    if (kb[KEY_ACTION]) input->action = true;
}
