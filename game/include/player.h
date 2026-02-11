#ifndef PLAYER_H
#define PLAYER_H

#include "input.h"

typedef struct {
    float x, y, w, h;
} Rectangle;

typedef struct {
    float x, y;
    float speed;
    Rectangle rect;
} Player;

void playerInit(Player* player);
void playerUpdate(Player* p, Input* input, float dt);

#endif
