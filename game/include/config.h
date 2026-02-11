#ifndef CONFIG_H
#define CONFIG_H

// Ekran Ayarları
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define WINDOW_TITLE  "Solveritius Game Engine"

#define FPS_TARGET 144
// 1000 milisaniye / 60 kare = Her kare yaklaşık 16.6 ms sürmeli
#define FRAME_TARGET_TIME (1000 / FPS_TARGET)

// Fizik Ayarları
#define MAX_DELTA_TIME 0.05f


// --- TUS ATAMALARI ---
#define KEY_UP      SDL_SCANCODE_W
#define KEY_DOWN    SDL_SCANCODE_S
#define KEY_LEFT    SDL_SCANCODE_A
#define KEY_RIGHT   SDL_SCANCODE_D
#define KEY_ACTION  SDL_SCANCODE_SPACE
#define KEY_EXIT    SDL_SCANCODE_ESCAPE


#endif