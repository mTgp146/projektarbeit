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

void Projectile::moveProjectile(TYPE type) {
    if (type == GALAXIP) {
        rect.y = rect.y - 6;
    } else if (type == ALIEN) {
        rect.y = rect.y + 2;
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