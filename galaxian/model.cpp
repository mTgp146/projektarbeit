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
    moveGalaxipProjectile();
    moveAliens();
    collisionCheck();
    alienDisplayChanger();
}

void Model::moveGalaxipProjectile() {
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
}

void Model::moveAliens() {
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
        if(projectileGalaxip.getRect().y > greenAliens[0].getRect().y
            && projectileGalaxip.getRect().y < greenAliens[20].getRect().y + greenAliens[20].getRect().h) {
            projectileBetweenAliens = true;
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
}

void Model::collisionCheck() {
    // check if Galaxip Projectile intersects with Green Aliens
    for(int i = 0; i < 30; i++) {
        if(greenAliens[i].isAlive() && intersects(projectileGalaxip.getRect(), greenAliens[i].getRect())) {
            greenAliens[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }
}

void Model::alienDisplayChanger() {
    // change alien display
    if(changeAlienDisplay()) {
        for(int i = 0; i < 30; i++) {
            int xPosGA = i%10;
            bool tex_1 = false;
            bool tex_2 = false;
            bool tex_3 = false;
            bool pos_even = xPosGA == 0 || xPosGA == 2 || xPosGA == 4 || xPosGA == 6 || xPosGA == 8;
            bool pos_odd  = xPosGA == 1 || xPosGA == 3 || xPosGA == 5 || xPosGA == 7 || xPosGA == 9;            
            bool pos_1_5_9= xPosGA == 1 || xPosGA == 5 || xPosGA == 9;
            bool pos_2_6  = xPosGA == 2 || xPosGA == 6;
            bool pos_3_7  = xPosGA == 3 || xPosGA == 7;
            bool pos_0_4_8= xPosGA == 0 || xPosGA == 4 || xPosGA == 8;
            
            //2123212321
            //3212321232
            //2321232123
            //1232123212
            
            if(alienFormationState == 0 || alienFormationState == 2) {
                tex_2 = pos_even;
                if(alienFormationState == 0) {
                    tex_1 = pos_1_5_9;
                    tex_3 = pos_3_7;
                } else {
                    tex_1 = pos_3_7;
                    tex_3 = pos_1_5_9;
                }
            } else {
                tex_2 = pos_odd;
                if(alienFormationState == 1) {
                    tex_1 = pos_2_6;
                    tex_3 = pos_0_4_8;
                } else {
                    tex_1 = pos_0_4_8;
                    tex_3 = pos_2_6;
                }
            }
            if(tex_1) {
                greenAliens[i].setTextureNumber(1);
            } else if(tex_2) {
                greenAliens[i].setTextureNumber(2);
            } else {
                greenAliens[i].setTextureNumber(3);
            }
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

bool Model::changeAlienDisplay() {
  if((SDL_GetTicks() - lastAlienDisplayChange) > 400) {
    if(alienFormationState < 3) {
      alienFormationState = alienFormationState + 1;
    } else {
      alienFormationState = 0;
    }
    lastAlienDisplayChange = SDL_GetTicks();
    return true;
  }
  return false;
}