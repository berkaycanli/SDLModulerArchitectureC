#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct
{
    bool quit;

    int moveX;   // -1, 0, 1
    int moveY;   // -1, 0, 1

    bool action; // space / fire vs.
} Input;


void inputInit(Input* input);
void inputUpdate(Input* input);
void inputClear(Input* input);

#endif
