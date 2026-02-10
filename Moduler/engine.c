#include "engine.h"
#include "render.h"
#include "update.h"

#include <stdio.h>

bool engineInit(Engine* engine)
{
    engine->running = true;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return false;
    }

    engine->window = SDL_CreateWindow(
        "SDL2 Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );

    if (!engine->window)
    {
        printf("Window error: %s\n", SDL_GetError());
        return false;
    }

    inputInit(&engine->input);
    renderInit(engine);

    return true;
}

void engineRun(Engine* engine)
{
    Uint32 lastTick = SDL_GetTicks();

    while (engine->running)
    {
        Uint32 currentTick = SDL_GetTicks();
        float dt = (currentTick - lastTick) / 1000.0f;
        lastTick = currentTick;

        inputUpdate(&engine->input);

        if (engine->input.quit)
            engine->running = false;

        
        updateGame(engine, dt);
        renderDraw(engine, dt);
        
        inputClear(&engine->input);
    }
}



void engineQuit(Engine* engine)
{
    renderQuit(engine);
    SDL_DestroyWindow(engine->window);
    SDL_Quit();
}
