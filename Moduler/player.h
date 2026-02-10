#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "input.h"

typedef struct Player
{
    float x, y;
    float speed;      // px / second
    SDL_Rect rect;    // render için
} Player;

void playerInit(Player* player);
void playerUpdate(Player* p, Input* input, float dt);
void playerDraw(Player* player, SDL_Renderer* renderer);

#endif // PLAYER_H
