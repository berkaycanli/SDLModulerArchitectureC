#include "render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

// Private (Gizli) değişkenler
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

bool renderInit(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) return false;

    return true;
}

void renderDraw(Player* p) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Çizim işlemi
    SDL_Rect rect = { (int)p->x, (int)p->y, (int)p->rect.w, (int)p->rect.h };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void renderQuit(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

