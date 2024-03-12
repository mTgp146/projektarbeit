#include "projectileGalaxip.h"

ProjectileGalaxip::ProjectileGalaxip(int x, int y) {
    rect.w = 2;
    rect.h = 8;
    rect.x = x;
    rect.y = y;
    realY = y;

    lastUpdate = SDL_GetTicks();
}

void ProjectileGalaxip::moveProjectile() {
    int dT = SDL_GetTicks() - lastUpdate;
    if(alive) {
        realY = realY - dT*0.5057;
    }
    rect.y = (int)realY;
    lastUpdate = SDL_GetTicks();
}