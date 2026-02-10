#include <SDL2/SDL.h>
#include <stdio.h>
#include "loop.h"

static int running = 1;

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

void initSDL(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init error: %s\n", SDL_GetError());
        running = 0;
        return;
    }

    window = SDL_CreateWindow(
        "Solveritius Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );

    if (!window)
    {
        printf("Window error: %s\n", SDL_GetError());
        running = 0;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        printf("Renderer error: %s\n", SDL_GetError());
        running = 0;
        return;
    }
}

void gameLoop(void)
{
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = 0;
        }

        // siyah ekran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

    }
}

void quitSDL(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
