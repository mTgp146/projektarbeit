#include "projectile.h"

SDL_Rect Projectile::getRect() const {
    return rect;
}

void Projectile::setX(int x) {
    rect.x = x;
}

void Projectile::setY(int y) {
    rect.y = y;
    realY = y;
}

bool Projectile::isAlive() const {
    return alive;
}

void Projectile::setAlive(bool alive) {
    this->alive = alive;
}

void Projectile::setLastUpdate() {
    lastUpdate = SDL_GetTicks();
}