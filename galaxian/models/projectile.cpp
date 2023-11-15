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
}

SDL_Rect Projectile::getRect() const {
    return rect;
}

void Projectile::moveProjectile() {
    if(alive) {
        if(type == GALAXIP) {
            if(rect.y <= 0) {

            }
            rect.y = rect.y - 6;
        } else if(type == ALIEN) {
            rect.y = rect.y + 2;
        }
    }
}

void Projectile::setX(int x) {
    rect.x = x;
}

void Projectile::setY(int y) {
    rect.y = y;
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