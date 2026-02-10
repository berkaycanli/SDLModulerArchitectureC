#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Input
{
    bool quit;
    const Uint8* keyboard;
} Input;

void inputInit(Input* input);
void inputUpdate(Input* input);
void inputClear(Input* input);

#endif
