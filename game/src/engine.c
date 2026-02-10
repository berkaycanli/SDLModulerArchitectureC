#include "engine.h"
#include "render.h"
#include "timer.h"

bool engineInit(Engine* engine) {
    if (!renderInit("External Harici", 800, 600)) {
        return false;
    }
    
    playerInit(&engine->player);
    inputInit(&engine->input);
    engine->running = true;
    return true;
}

void engineRun(Engine* engine) {
    // Delta time ve loop mantığı buraya gelecek
    float lastTime = timerGetSeconds();

    while (engine->running) {

        // --- DELTA TIME HESAPLAMA ---
        float currentTime = timerGetSeconds();
        float dt = currentTime - lastTime;
        lastTime = currentTime;

        // ÖNEMLİ: Delta time çok büyükse (örneğin pencereyi sürüklerken oyun donarsa) 
        // karakterin bir anda duvarların içinden geçmemesi için bir üst limit koyuyoruz.
        if (dt > 0.1f) dt = 0.1f;

        inputUpdate(&engine->input);
        if (engine->input.quit) engine->running = false;

        // --- UPDATE ---
        // Artık gerçek 'dt' değerini gönderiyoruz
        playerUpdate(&engine->player, &engine->input, dt);
        
        renderDraw(&engine->player);
    }
}

void engineQuit(Engine* engine) {
    renderQuit();
}