#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>
#include "input.h"
#include "player.h"

typedef struct {
    Player player;
    Input input;
    bool running;
} Engine;

bool engineInit(Engine* engine);
void engineRun(Engine* engine);
void engineQuit(Engine* engine);

#endif