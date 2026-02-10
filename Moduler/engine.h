#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "input.h"
#include "player.h"

typedef struct Engine
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    Player player;
    Input input;
    bool running;
} Engine;

bool engineInit(Engine* engine);
void engineRun(Engine* engine);
void engineQuit(Engine* engine);

#endif
