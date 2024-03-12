#include "projectileAlien.h"

ProjectileAlien::ProjectileAlien() {
    rect.w = 2;
    rect.h = 4;
    rect.x = 0;
    rect.y = 0;

    lastUpdate = SDL_GetTicks();
}

void ProjectileAlien::moveProjectile() {
    int dT = SDL_GetTicks() - lastUpdate;
    if(alive) {
        // differ speed of the different types of projectiles
        realY = realY + dT*0.00058 * (heightOfGalaxip - initialY) * (1 + (type/3.0f));
        rect.y = (int)realY;
        realX = realX + dT*0.000535 * (galaxyPosX - initialX) * (1 + (type/3.0f));
        rect.x = (int)realX;
    }
    lastUpdate = SDL_GetTicks();
}

void ProjectileAlien::shoot(int x, int y, int galaxipPosX, Types type) {
    rect.x = x;
    rect.y = y;
    realY = y;
    realX = x;
    initialY = (float)y;
    initialX = (float)x;
    alive = true;
    galaxyPosX = (float)galaxipPosX;
    lastUpdate = SDL_GetTicks();
    this->type = type;
}