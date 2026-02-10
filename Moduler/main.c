#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "engine.h"

int main(int argc, char* argv[])
{
    Engine engine;

    if (!engineInit(&engine))
        return 1;

    engineRun(&engine);
    engineQuit(&engine);

    return 0;
}
