#include "model.h"

void Model::initAliens() {

    for(int i = 0; i < 10; i++) {
        aliens.push_back(Flagship{i});
        std::get<Flagship>(aliens[i]).setType(Flagship::Type::FLAGSHIP);
    }

    for(int i = 10; i < 20; i++) {
        aliens.push_back(RedAlien{i});
        std::get<RedAlien>(aliens[i]).setType(RedAlien::Type::RED);
    }

    for(int i = 20; i < 30; i++) {
        aliens.push_back(BlueAlien{i});
        std::get<BlueAlien>(aliens[i]).setType(BlueAlien::Type::BLUE);
    }

    for(int i = 30; i < 60; i++) {
        aliens.push_back(GreenAlien{i});
        std::get<GreenAlien>(aliens[i]).setType(GreenAlien::Type::GREEN);
    }

    /* init Green Aliens
    for(int i = 0; i < 30; i++) {
        greenAliens[i].setPositionInFormation(i);
    }
    // init Blue Aliens
    for(int i = 0; i < 8; i++) {
        blueAliens[i].setPositionInFormation(i);
    }
    // init Red Aliens
    for(int i = 0; i < 6; i++) {
        redAliens[i].setPositionInFormation(i);
    }
    // init Flagships
    for(int i = 0; i < 10; i++) {
        if(i == 3 || i == 6) {
            flagships[i].setPositionInFormation(i);
        } else {
            flagships[i].setAlive(false);
        }
    }*/
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
    return std::get<GreenAlien>(aliens[index]);
}

BlueAlien Model::getBlueAlien(int index) {
    return std::get<BlueAlien>(aliens[index]);
}

RedAlien Model::getRedAlien(int index) {
    return std::get<RedAlien>(aliens[index]);
}

Flagship Model::getFlagship(int index) {
    return std::get<Flagship>(aliens[index]);
}

Alien::Type Model::getAlienType(int index) {
    Alien::Type type = Alien::Type::NONE;
    if(std::holds_alternative<GreenAlien>(aliens[index]))
        type = Alien::Type::GREEN;
    else if(std::holds_alternative<BlueAlien>(aliens[index]))
        type = Alien::Type::BLUE;
    else if(std::holds_alternative<RedAlien>(aliens[index]))
        type = Alien::Type::RED;
    else if(std::holds_alternative<Flagship>(aliens[index]))
        type = Alien::Type::FLAGSHIP;
    return type;
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
    updateBackground();
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
    // move Aliens
    // only if projectile is not between aliens
/*    bool projectileBetweenAliens = false;
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
                for(int i = 0; i < 8; i++) {
                    blueAliens[i].changeDirection();
                }
                for(int i = 0; i < 6; i++) {
                    redAliens[i].changeDirection();
                }
                for(int i = 0; i < 10; i++) {
                    flagships[i].changeDirection();
                }
            }
        } else {
            if(greenAliens[0].getRect().x >= 140) {
                for(int i = 0; i < 30; i++) {
                    greenAliens[i].changeDirection();
                }
                for(int i = 0; i < 8; i++) {
                    blueAliens[i].changeDirection();
                }
                for(int i = 0; i < 6; i++) {
                    redAliens[i].changeDirection();
                }
                for(int i = 0; i < 10; i++) {
                    flagships[i].changeDirection();
                }
            }
        }
        // random number between 0 and 30
        /*int randomNumber = rand() % 30;
        if(greenAliens[randomNumber].isAlive() && attack) {
            greenAliens[randomNumber].setAttackMode(true);
            attack = false;
        }*/
/*
        for(int i = 0; i < 30; i++) {
            //if(greenAliens[i].isInAttackMode()) {
             //   greenAliens[i].moveAlien();
            //} else {
                greenAliens[i].moveAlienAlongXAxis();
            //}
        }
        for(int i = 0; i < 8; i++) {
            blueAliens[i].moveAlienAlongXAxis();
        }
        for(int i = 0; i < 6; i++) {
            redAliens[i].moveAlienAlongXAxis();
        }
        for(int i = 0; i < 10; i++) {
            flagships[i].moveAlienAlongXAxis();
        }
    } else {
        for(int i = 0; i < 30; i++) {
            greenAliens[i].setLastUpdate();
        }
        for(int i = 0; i < 8; i++) {
            blueAliens[i].setLastUpdate();
        }
        for(int i = 0; i < 6; i++) {
            redAliens[i].setLastUpdate();
        }
        for(int i = 0; i < 10; i++) {
            flagships[i].setLastUpdate();
        }
    }*/
}

void Model::collisionCheck() {
    // check if Galaxip Projectile intersects with Green Aliens
   /* for(int i = 0; i < 30; i++) {
        if(greenAliens[i].isAlive() && intersects(projectileGalaxip.getRect(), greenAliens[i].getRect())) {
            greenAliens[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }
    // check if Galaxip Projectile intersects with Blue Aliens
    for(int i = 0; i < 8; i++) {
        if(blueAliens[i].isAlive() && intersects(projectileGalaxip.getRect(), blueAliens[i].getRect())) {
            blueAliens[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }
    // check if Galaxip Projectile intersects with Red Aliens
    for(int i = 0; i < 6; i++) {
        if(redAliens[i].isAlive() && intersects(projectileGalaxip.getRect(), redAliens[i].getRect())) {
            redAliens[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }
    // check if Galaxip Projectile intersects with Flagships
    for(int i = 0; i < 10; i++) {
        if(flagships[i].isAlive() && intersects(projectileGalaxip.getRect(), flagships[i].getRect())) {
            flagships[i].setAlive(false);
            resetGalaxipProjectile();
        }
    }*/
}

void Model::alienDisplayChanger() {
    // change alien display
   /* if(changeAlienDisplay()) {
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
        for(int i = 0; i < 8; i++) {
            blueAliens[i].setTextureNumber(greenAliens[i+1].getTextureNumber());
        }
        for(int i = 0; i < 6; i++) {
            redAliens[i].setTextureNumber(greenAliens[i+2].getTextureNumber());
        }
    }*/
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
///
   // attack = true;
///
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

void Model::updateBackground() {
    background.update();
}

std::array<BackgroundParticle, 128> Model::getBackgroundParticles() {
    return background.getParticles();
}