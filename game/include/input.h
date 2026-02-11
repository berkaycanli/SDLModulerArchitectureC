#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

typedef struct {
    bool quit;
    int moveX;
    int moveY;
    bool action;
} Input;

void inputInit(Input* input);
void inputUpdate(Input* input);

#endif