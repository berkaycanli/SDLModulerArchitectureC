#include "player.h"
#include "config.h"

void playerInit(Player* player) {
    player->x = (float)SCREEN_WIDTH / 2 - 25;
    player->y = (float)SCREEN_HEIGHT / 2 - 25;
    player->speed = 300.0f;
    player->rect.w = 50;
    player->rect.h = 50;
}

void playerUpdate(Player* p, Input* input, float dt) {
    float nextX = p->x + (input->moveX * p->speed * dt);
    float nextY = p->y + (input->moveY * p->speed * dt);

    if (nextX >= 0 && nextX <= (SCREEN_WIDTH - p->rect.w)) {
        p->x = nextX;
    }
    if (nextY >= 0 && nextY <= (SCREEN_HEIGHT - p->rect.h)) {
        p->y = nextY;
    }

    p->rect.x = p->x;
    p->rect.y = p->y;
}

