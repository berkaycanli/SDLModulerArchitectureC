#include "collision.h"

bool collisionCheck(Rectangle a, Rectangle b) {
    // Eğer kutulardan biri diğerinin tamamen dışında kalıyorsa çarpışma yoktur.
    // Bu mantığın tersini kontrol etmek en hızlı yoldur:
    if (a.x + a.w <= b.x) return false; // a, b'nin solunda
    if (a.x >= b.x + b.w) return false; // a, b'nin sağında
    if (a.y + a.h <= b.y) return false; // a, b'nin üstünde
    if (a.y >= b.y + b.h) return false; // a, b'nin altında

    // Yukarıdaki şartların hiçbiri sağlanmıyorsa kutular kesişiyor demektir.
    return true;
}