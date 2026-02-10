#ifndef PLAYER_H
#define PLAYER_H

#include "input.h"

typedef struct Rectangel
{
    float x,y,w,h;
}Rectangle;


typedef struct Player
{
    float x, y;
    float speed;      // px / second
    Rectangle rect;    // render için
} Player;

void playerInit(Player* player);
void playerUpdate(Player* p, Input* input, float dt);
void playerDraw(Player* player, SDL_Renderer* renderer);

#endif // PLAYER_H
