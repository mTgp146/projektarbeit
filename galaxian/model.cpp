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
    if(!projectileGalaxip.isAlive()) {
        projectileGalaxip.setAlive(true);
    }
}

void Model::resetGalaxipProjectile() {
    projectileGalaxip.setAlive(false);
    projectileGalaxip.setX(galaxip.getRect().x+15);
    projectileGalaxip.setY(galaxip.getRect().y-8);
}

void Model::gameActions() {
    if(projectileGalaxip.isAlive()) {
        if(projectileGalaxip.getRect().y <= 0) {
            resetGalaxipProjectile();
        } else {
            projectileGalaxip.moveProjectile();
        }
    } else {
        projectileGalaxip.setX(galaxip.getRect().x+15);
    }
}