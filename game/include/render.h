#ifndef RENDER_H
#define RENDER_H

#include "player.h"

// Motor başlatılırken pencereyi de burada açacağız
bool renderInit(const char* title, int width, int height);

// Sadece ihtiyaç duyduğumuz veriyi (Player) gönderiyoruz
void renderDraw(Player* p);

void renderQuit(void);

#endif