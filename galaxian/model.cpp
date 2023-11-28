#include "model.h"

void Model::initAliens() {
    for(int i = 0; i < 30; i++) {
        greenAliens[i].setPositionInFormation(i);
    }
}

Galaxip Model::getGalaxip() {
    return galaxip;
}

void Model::setGalaxipDT() {
    galaxip.setLastUpdate();
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
    projectileGalaxip.setLastUpdate();
}

void Model::gameActions() {
    // move Galaxip Projectile
    if(projectileGalaxip.isAlive()) {
        if(projectileGalaxip.getRect().y <= 0) {
            resetGalaxipProjectile();
        } else {
            projectileGalaxip.moveProjectile();
        }
    } else {
        projectileGalaxip.setX(galaxip.getRect().x+15);
        projectileGalaxip.setLastUpdate();
    }

    // move Green Aliens
    // only if projectile is not between aliens
    bool projectileBetweenAliens = false;
    if(projectileGalaxip.isAlive()) {
        for(int i = 0; i < 10; i++) {
            if((projectileGalaxip.getRect().x > greenAliens[i].getRect().x + greenAliens[i].getRect().w 
                && projectileGalaxip.getRect().x < greenAliens[i].getRect().x + greenAliens[i].getRect().w + 4)
                    || (projectileGalaxip.getRect().x + projectileGalaxip.getRect().w < greenAliens[i].getRect().x 
                        && projectileGalaxip.getRect().x + projectileGalaxip.getRect().w > greenAliens[i].getRect().x - 4)) {
                projectileBetweenAliens = true;
            }
        }
    }
    if(!projectileBetweenAliens) {
        if(greenAliens[0].getDirection() == GreenAlien::Direction::LEFT) {
            if(greenAliens[0].getRect().x <= 76) {
                for(int i = 0; i < 30; i++) {
                    greenAliens[i].changeDirection();
                }
            }
        } else {
            if(greenAliens[0].getRect().x >= 140) {
                for(int i = 0; i < 30; i++) {
                    greenAliens[i].changeDirection();
                }
            }
        }
        for(int i = 0; i < 30; i++) {
            greenAliens[i].moveGreenAlienAlongXAxis();
        }
    } else {
        for(int i = 0; i < 30; i++) {
            greenAliens[i].setLastUpdate();
        }
    }

    // check if Galaxip Projectile intersects with Green Aliens
    for(int i = 0; i < 30; i++) {
        if(greenAliens[i].isAlive() && intersects(projectileGalaxip.getRect(), greenAliens[i].getRect())) {
            greenAliens[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }
}

bool Model::intersects(SDL_Rect rect1, SDL_Rect rect2) {
    if(rect1.x < rect2.x + rect2.w && rect1.x + rect1.w > rect2.x && 
        rect1.y < rect2.y + rect2.h && rect1.y + rect1.h > rect2.y) {
        return true;
    } else {
        return false;
    }
}
