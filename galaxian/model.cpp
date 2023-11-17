#include "model.h"

void Model::initAliens() {
    for(int i = 0; i < 30; i++) {
        greenAliens[i].setPositionInFormation(i);
    }
}

Galaxip Model::getGalaxip() {
    return galaxip;
}

Projectile Model::getGalaxipProjectile() {
    return projectileGalaxip;
}

GreenAlien Model::getGreenAlien(int index) {
    return greenAliens[index];
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

    //move Galaxip Projectile
    if(projectileGalaxip.isAlive()) {
        if(projectileGalaxip.getRect().y <= 0) {
            resetGalaxipProjectile();
        } else {
            projectileGalaxip.moveProjectile();
        }
    } else {
        projectileGalaxip.setX(galaxip.getRect().x+15);
    }

    //move Green Aliens
    
    // -> check if left/right
    // -> check if at edge
    // -> if at edge, change direction
    // -> move direction of 1./30.
    
    /*if(greenAliens[0].getDirection() == GreenAlien::Direction::LEFT) {
        if(greenAliens[0].getRect().x <= 0) {
            for(int i = 0; i < 30; i++) {
                greenAliens[i].changeDirection();
                greenAliens[i].setY(greenAliens[i].getRect().y+2);
            }
        }
    } else {
        if(greenAliens[29].getRect().x >= 486) {
            for(int i = 0; i < 30; i++) {
                greenAliens[i].changeDirection();
                greenAliens[i].setY(greenAliens[i].getRect().y+2);
            }
        }
    }*/
    for(int i = 0; i < 30; i++) {
        greenAliens[i].moveGreenAlienAlongXAxis();
    }
}