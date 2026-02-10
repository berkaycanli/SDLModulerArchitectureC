#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include "loop.h"

int main(int argc, char* argv[])
{
    initSDL();
    gameLoop();
    quitSDL();
    return 0;
}
