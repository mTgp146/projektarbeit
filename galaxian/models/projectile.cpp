#include "projectile.h"

Projectile::Projectile(TYPE type, int x, int y) {
    this->type = type;
    if (type == GALAXIP) {   
        rect.w = 2;
        rect.h = 8;
    }
    else if (type == ALIEN) {
        rect.w = 2;
        rect.h = 4;
    }
    
    rect.x = x;
    rect.y = y;
    realY = y;

    lastUpdate = SDL_GetTicks();
}

SDL_Rect Projectile::getRect() const {
    return rect;
}

void Projectile::moveProjectile() {
    int dT = SDL_GetTicks() - lastUpdate;
    if(alive) {
        //if(type == GALAXIP) {
            realY = realY - dT*0.5057;
        //} else if(type == ALIEN) {
            //rect.y = rect.y + 2;
        //}
    }
    rect.y = (int)realY;
    lastUpdate = SDL_GetTicks();
}

void Projectile::setX(int x) {
    rect.x = x;
}

void Projectile::setY(int y) {
    rect.y = y;
    realY = y;
}

Projectile::TYPE Projectile::getType() const {
    return type;
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