#include "engine.h"
#include "render.h"
#include "timer.h"
#include "config.h"

bool engineInit(Engine* engine) {
    if (!renderInit(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT))
        return false;

    timerInit();
    playerInit(&engine->player);
    inputInit(&engine->input);
    engine->running = true;
    return true;
}

void engineRun(Engine* engine) {
    while (engine->running) {
        timerUpdate();
        float dt = timerGetDelta();

        inputUpdate(&engine->input);
        if (engine->input.quit) engine->running = false;

        playerUpdate(&engine->player, &engine->input, dt);

        renderBegin();
        renderDrawRect(
            engine->player.x, 
            engine->player.y, 
            engine->player.rect.w, 
            engine->player.rect.h, 
            255, 255, 255, 255
        );
        renderEnd();

        timerSync(FPS_TARGET);
    }
}

void engineQuit(Engine* engine) {
    renderQuit();
}