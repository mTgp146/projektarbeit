#include "model.h"

Galaxip Model::getGalaxip() {
    return galaxip;
}

Projectile Model::getGalaxipProjectile() {
    return projectileGalaxip;
}

void Model::moveGalaxip(enum Galaxip::Direction direction) {
    galaxip.moveGalaxip(direction);
}

void Model::shotByGalaxip() {
    projectileGalaxip.setX(galaxip.getRect().x+15);
    projectileGalaxip.setY(galaxip.getRect().y-8);
}

void Model::gameActions() {
    projectileGalaxip.moveProjectile(Projectile::TYPE::GALAXIP);
}