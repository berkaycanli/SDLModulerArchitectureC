#include "player.h"

void playerInit(Player* player)
{
    player->x = 400.0f;
    player->y = 300.0f;
    player->speed = 300.0f;

    player->rect.w = 50;
    player->rect.h = 50;
}

void playerUpdate(Player* p,  Input* input, float dt)
{
    // 1. Önce yeni pozisyonu hesapla
    float nextX = p->x + (input->moveX * p->speed * dt);
    float nextY = p->y + (input->moveY * p->speed * dt);

    // 2. Ekran sınırları için basit çarpışma kontrolü (Örn: 800x600 pencere)
    // Bu, "collisionCheck" fonksiyonumuzun en temel mantığıdır.
    if (nextX >= 0 && nextX <= (800 - p->rect.w)) {
        p->x = nextX;
    }
    if (nextY >= 0 && nextY <= (600 - p->rect.h)) {
        p->y = nextY;
    }

    p->rect.x = (int)p->x;
    p->rect.y = (int)p->y;
}

