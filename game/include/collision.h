#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>
#include "player.h" // Rectangle struct'ını kullanmak için

// AABB (Axis-Aligned Bounding Box) Çarpışma Testi
// İki kutunun birbiriyle kesişip kesişmediğini kontrol eder.
bool collisionCheck(Rectangle a, Rectangle b);

#endif