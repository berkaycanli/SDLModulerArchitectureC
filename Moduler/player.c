#include "player.h"

void playerInit(Player* player)
{
    player->x = 400.0f;
    player->y = 300.0f;
    player->speed = 300.0f;

    player->rect.w = 50;
    player->rect.h = 50;
}

void playerUpdate(Player* p,  Input* input, float dt)
{
    p->x += input->moveX * p->speed * dt;
    p->y += input->moveY * p->speed * dt;

    p->rect.x = (int)p->x;
    p->rect.y = (int)p->y;
}



void playerDraw(Player* player, SDL_Renderer* renderer)
{
    SDL_RenderFillRect(renderer, &player->rect);
}
