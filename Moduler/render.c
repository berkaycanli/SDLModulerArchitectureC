#include "render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

void renderInit(Engine* engine)
{
    engine->renderer = SDL_CreateRenderer(
        engine->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (!engine->renderer)
        printf("Renderer error: %s\n", SDL_GetError());
}


void renderDraw(Engine* engine, float dt)
{
    (void)dt;

    SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine->renderer);
    SDL_RenderPresent(engine->renderer);
}


void renderQuit(Engine* engine)
{
    SDL_DestroyRenderer(engine->renderer);
}

