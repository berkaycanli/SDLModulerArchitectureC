#include "update.h"
#include "player.h"

void updateGame(Engine* engine, float dt)
{
    playerUpdate(&engine->player, &engine->input, dt);

    if (engine->input.quit)
    {
        engine->running = false;
    }
}
