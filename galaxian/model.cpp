#include "model.h"
#include <cstdio>

void Model::initAliens() {
    FILE *file;
    file = fopen("alien_formation_test.txt", "r");
    char row1[100];
    char row2[100];
    char row3[100];
    char row4[100];
    char row5[100];
    char row6[100];
    std::array<char, 60> formation = {};
    fgets(row1, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i] = row1[i];
    }
    fgets(row2, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i+10] = row2[i];
    }
    fgets(row3, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i+20] = row3[i];
    }
    fgets(row4, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i+30] = row4[i];
    }
    fgets(row5, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i+40] = row5[i];
    }
    fgets(row6, 100, file);
    for(int i = 0; i < 10; i++) {
        formation[i+50] = row6[i];
    }

    // init Green Aliens
    for(int i = 0; i < 60; i++) {
        if(formation[i] == 'G') {
            greenAliens[i].setInGame(true);
            greenAliens[i].setAlive(true);
            greenAliens[i].setAttackMode(false);
            greenAliens[i].setReturnMode(false);
        }
        greenAliens[i].setPositionInFormation(i);
    }

    // init Blue Aliens
    for(int i = 0; i < 60; i++) {
        if(formation[i] == 'B') {
            blueAliens[i].setInGame(true);
            blueAliens[i].setAlive(true);
            blueAliens[i].setAttackMode(false);
            blueAliens[i].setReturnMode(false);
        }
        blueAliens[i].setPositionInFormation(i);
    }

    // init Red Aliens
    for(int i = 0; i < 60; i++) {
        if(formation[i] == 'R') {
            redAliens[i].setInGame(true);
            redAliens[i].setAlive(true);
            redAliens[i].setAttackMode(false);
            redAliens[i].setReturnMode(false);
        }
        redAliens[i].setPositionInFormation(i);
    }

    // init Flagships
    for(int i = 0; i < 60; i++) {
        if(formation[i] == 'F') {
            flagships[i].setInGame(true);
            flagships[i].setAlive(true);
            flagships[i].setAttackMode(false);
            flagships[i].setReturnMode(false);
        }
        flagships[i].setPositionInFormation(i);
    }
}

Galaxip Model::getGalaxip() {
    return galaxip;
}

void Model::setGalaxipDT() {
    galaxip.setLastUpdate();
}

ProjectileGalaxip Model::getGalaxipProjectile() {
    return projectileGalaxip;
}

ProjectileAlien Model::getAlienProjectile(int index) {
    return projectilesAlien[index];
}

Alien Model::getGreenAlien(int index) {
    return greenAliens[index];
}

Alien Model::getBlueAlien(int index) {
    return blueAliens[index];
}

Alien Model::getRedAlien(int index) {
    return redAliens[index];
}

Alien Model::getFlagship(int index) {
    return flagships[index];
}

void Model::moveGalaxip(enum Galaxip::Direction direction) {
    galaxip.moveGalaxip(direction);
}

void Model::shotByGalaxip() {
    if(!projectileGalaxip.isAlive() && galaxip.isAlive()) {
        projectileGalaxip.setAlive(true);
        sounds.playShot();
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
    moveAlienShots();
    tryToReviveGalaxip();
    checkForNewAttack();
    checkExplosions();
    checkIfAllAliensAreDead();
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
        if(greenAliens[0].getDirection() == Alien::Direction::LEFT) {
            if(greenAliens[0].getRect().x <= 76) {
                for(int i = 0; i < 60; i++) {
                    greenAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    blueAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    redAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    flagships[i].changeDirection();
                }
            }
        } else {
            if(greenAliens[0].getRect().x >= 140) {
                for(int i = 0; i < 60; i++) {
                    greenAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    blueAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    redAliens[i].changeDirection();
                }
                for(int i = 0; i < 60; i++) {
                    flagships[i].changeDirection();
                }
            }
        }

        for(int i = 0; i < 60; i++) {
            if((i%10) < 5) {
                greenAliens[i].moveAlien(galaxip.getX(), Alien::Direction::LEFT);
                blueAliens[i].moveAlien(galaxip.getX(), Alien::Direction::LEFT);
                redAliens[i].moveAlien(galaxip.getX(), Alien::Direction::LEFT);
                flagships[i].moveAlien(galaxip.getX(), Alien::Direction::LEFT);
            } else {
                greenAliens[i].moveAlien(galaxip.getX(), Alien::Direction::RIGHT);
                blueAliens[i].moveAlien(galaxip.getX(), Alien::Direction::RIGHT);
                redAliens[i].moveAlien(galaxip.getX(), Alien::Direction::RIGHT);
                flagships[i].moveAlien(galaxip.getX(), Alien::Direction::RIGHT);
            }
        }
    } else {
        if(alienInAttack) {
            moveAttackingAlien();
        }
        for(int i = 0; i < 60; i++) {
            greenAliens[i].setLastUpdate();
            blueAliens[i].setLastUpdate();
            redAliens[i].setLastUpdate();
            flagships[i].setLastUpdate();
        }
    }
    // check if alien is out of screen
    if(alienInAttack) {
        if(attackingAlienType == G) {
            if(greenAliens[attackingAlien].getRect().y > 512) {
                alienInAttack = false;
                greenAliens[attackingAlien].setAttackMode(false);
                greenAliens[attackingAlien].setReturnMode(true);
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == B) {
            if(blueAliens[attackingAlien].getRect().y > 512) {
                alienInAttack = false;
                blueAliens[attackingAlien].setAttackMode(false);
                blueAliens[attackingAlien].setReturnMode(true);
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == R) {
            if(redAliens[attackingAlien].getRect().y > 512) {
                alienInAttack = false;
                redAliens[attackingAlien].setAttackMode(false);
                redAliens[attackingAlien].setReturnMode(true);
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == F) {
            if(flagships[attackingAlien].getRect().y > 512) {
                alienInAttack = false;
                flagships[attackingAlien].setAttackMode(false);
                flagships[attackingAlien].setReturnMode(true);
                lastAttack = SDL_GetTicks();
            }
        }
    }
}

void Model::collisionCheck() {
    // check if Galaxip Projectile intersects with Green Aliens
    for(int i = 0; i < 60; i++) {
        if(greenAliens[i].isInGame() && greenAliens[i].isAlive() && projectileGalaxip.isAlive() && intersects(projectileGalaxip.getRect(), greenAliens[i].getRect())) {
            sounds.playExplosion();
            greenAliens[i].setAlive(false);
            resetGalaxipProjectile();
            if(greenAliens[i].isInAttackMode()) {
                alienInAttack = false;
                points.addPoints(Points::Values::GREEN_ATTACK);
                lastAttack = SDL_GetTicks();
            } else {
                points.addPoints(Points::Values::GREEN_FORMATION);
            }
            greenAliens[i].increaseDyingAnimationCounter();
        }
    }
    // check if Galaxip Projectile intersects with Blue Aliens
    for(int i = 0; i < 60; i++) {
        if(blueAliens[i].isInGame() && blueAliens[i].isAlive() && projectileGalaxip.isAlive() && intersects(projectileGalaxip.getRect(), blueAliens[i].getRect())) {
            sounds.playExplosion();
            blueAliens[i].setAlive(false);
            resetGalaxipProjectile();
            if(blueAliens[i].isInAttackMode()) {
                alienInAttack = false;
                points.addPoints(Points::Values::BLUE_ATTACK);
                lastAttack = SDL_GetTicks();
            } else {
                points.addPoints(Points::Values::BLUE_FORMATION);
            }
            blueAliens[i].increaseDyingAnimationCounter();
        }
    }
    // check if Galaxip Projectile intersects with Red Aliens
    for(int i = 0; i < 60; i++) {
        if(redAliens[i].isInGame() && redAliens[i].isAlive() && projectileGalaxip.isAlive() && intersects(projectileGalaxip.getRect(), redAliens[i].getRect())) {
            sounds.playExplosion();
            redAliens[i].setAlive(false);
            resetGalaxipProjectile();
            if(redAliens[i].isInAttackMode()) {
                alienInAttack = false;
                points.addPoints(Points::Values::RED_ATTACK);
                lastAttack = SDL_GetTicks();
            } else {
                points.addPoints(Points::Values::RED_FORMATION);
            }
            redAliens[i].increaseDyingAnimationCounter();
        }
    }
    // check if Galaxip Projectile intersects with Flagships
    for(int i = 0; i < 60; i++) {
        if(flagships[i].isInGame() && flagships[i].isAlive() && projectileGalaxip.isAlive() && intersects(projectileGalaxip.getRect(), flagships[i].getRect())) {
            sounds.playExplosion();
            flagships[i].setAlive(false);
            resetGalaxipProjectile();
            if(flagships[i].isInAttackMode()) {
                alienInAttack = false;
                points.addPoints(Points::Values::FLAGSHIP_ATTACK_SOLO);
                lastAttack = SDL_GetTicks();
            } else {
                points.addPoints(Points::Values::FLAGSHIP_FORMATION);
            }
            flagships[i].increaseDyingAnimationCounter();
        }
    }
    // check if Alien Projectile intersects with Galaxip
    for(int i = 0; i < 2; i++) {
        if(galaxip.isAlive() && projectilesAlien[i].isAlive() && intersects(projectilesAlien[i].getRect(), galaxip.getRect())) {
            sounds.playExplosion();
            galaxip.loseLife();
            projectilesAlien[i].setAlive(false);
            lastDeath = SDL_GetTicks();
            galaxip.increaseDyingAnimationCounter();
        }
    }
    // check if attacking Alien intersects with Galaxip
    if(alienInAttack) {
        if(attackingAlienType == G) {
            if(galaxip.isAlive() && intersects(galaxip.getRect(), greenAliens[attackingAlien].getRect())) {
                sounds.playExplosion();
                galaxip.loseLife();
                alienInAttack = false;
                lastDeath = SDL_GetTicks();
                greenAliens[attackingAlien].setAttackMode(false);
                greenAliens[attackingAlien].setAlive(false);
                greenAliens[attackingAlien].increaseDyingAnimationCounter();
                points.addPoints(Points::Values::GREEN_ATTACK);
                galaxip.increaseDyingAnimationCounter();
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == B) {
            if(galaxip.isAlive() && intersects(galaxip.getRect(), blueAliens[attackingAlien].getRect())) {
                sounds.playExplosion();
                galaxip.loseLife();
                alienInAttack = false;
                lastDeath = SDL_GetTicks();
                blueAliens[attackingAlien].setAttackMode(false);
                blueAliens[attackingAlien].setAlive(false);
                blueAliens[attackingAlien].increaseDyingAnimationCounter();
                points.addPoints(Points::Values::BLUE_ATTACK);
                galaxip.increaseDyingAnimationCounter();
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == R) {
            if(galaxip.isAlive() && intersects(galaxip.getRect(), redAliens[attackingAlien].getRect())) {
                sounds.playExplosion();
                galaxip.loseLife();
                alienInAttack = false;
                lastDeath = SDL_GetTicks();
                redAliens[attackingAlien].setAttackMode(false);
                redAliens[attackingAlien].setAlive(false);
                redAliens[attackingAlien].increaseDyingAnimationCounter();
                points.addPoints(Points::Values::RED_ATTACK);
                galaxip.increaseDyingAnimationCounter();
                lastAttack = SDL_GetTicks();
            }
        } else if(attackingAlienType == F) {
            if(galaxip.isAlive() && intersects(galaxip.getRect(), flagships[attackingAlien].getRect())) {
                sounds.playExplosion();
                galaxip.loseLife();
                alienInAttack = false;
                lastDeath = SDL_GetTicks();
                flagships[attackingAlien].setAttackMode(false);
                flagships[attackingAlien].setAlive(false);
                flagships[attackingAlien].increaseDyingAnimationCounter();
                points.addPoints(Points::Values::FLAGSHIP_ATTACK_SOLO);
                galaxip.increaseDyingAnimationCounter();
                lastAttack = SDL_GetTicks();
            }
        }
    }
}

void Model::alienDisplayChanger() {
    // change alien display
    if(changeAlienDisplay()) {
        for(int i = 0; i < 60; i++) {
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
                blueAliens[i].setTextureNumber(1);
                redAliens[i].setTextureNumber(1);
            } else if(tex_2) {
                greenAliens[i].setTextureNumber(2);
                blueAliens[i].setTextureNumber(2);
                redAliens[i].setTextureNumber(2);
            } else {
                greenAliens[i].setTextureNumber(3);
                blueAliens[i].setTextureNumber(3);
                redAliens[i].setTextureNumber(3);
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

void Model::updateBackground() {
    background.update();
}

std::array<BackgroundParticle, 128> Model::getBackgroundParticles() {
    return background.getParticles();
}

void Model::startMusic() {
    sounds.playBackground();
}

void Model::addPoints(Points::Values value) {
    points.addPoints(value);
}

int Model::getPoints() {
    return points.getPoints();
}

void Model::resetPoints() {
    points.resetPoints();
}

void Model::moveAlienShots() {
    for(int i = 0; i < 2; i++) {
        if(projectilesAlien[i].isAlive()) {
            projectilesAlien[i].moveProjectile();
        } else if(alienInAttack) {
            if(isAttackingAlienMovingToMiddle() && SDL_GetTicks() - lastShot > 300) {
                projectilesAlien[i].shoot(getAttackingAlienX()+10, getAttackingAlienY()+11, galaxip.getX(), static_cast<ProjectileAlien::Types>(attackingAlienType));
                sounds.playShot();
                lastShot = SDL_GetTicks();
            }
        }
        if(projectilesAlien[i].getRect().y > 512) {
            projectilesAlien[i].setAlive(false);
        }
    }
}

void Model::tryToReviveGalaxip() {
    if(!galaxip.isAlive()) {
        if(SDL_GetTicks() - lastDeath > 3000) {
            galaxip.setAlive(true);
            galaxip.setX(240);
        }
    }
}

bool Model::isAttackingAlienMovingToMiddle() {
    if(attackingAlienType == G) {
        if(greenAliens[attackingAlien].isIsMovingToMiddle()) {
            return true;
        }
    } else if(attackingAlienType == B) {
        if(blueAliens[attackingAlien].isIsMovingToMiddle()) {
            return true;
        }
    } else if(attackingAlienType == R) {
        if(redAliens[attackingAlien].isIsMovingToMiddle()) {
            return true;
        }
    } else if(attackingAlienType == F) {
        if(flagships[attackingAlien].isIsMovingToMiddle()) {
            return true;
        }
    }
    return false;
}

int Model::getAttackingAlienX() {
    if(attackingAlienType == G) {
        return greenAliens[attackingAlien].getRect().x;
    } else if(attackingAlienType == B) {
        return blueAliens[attackingAlien].getRect().x;
    } else if(attackingAlienType == R) {
        return redAliens[attackingAlien].getRect().x;
    } else if(attackingAlienType == F) {
        return flagships[attackingAlien].getRect().x;
    }
    return -1;
}

int Model::getAttackingAlienY() {
    if(attackingAlienType == G) {
        return greenAliens[attackingAlien].getRect().y;
    } else if(attackingAlienType == B) {
        return blueAliens[attackingAlien].getRect().y;
    } else if(attackingAlienType == R) {
        return redAliens[attackingAlien].getRect().y;
    } else if(attackingAlienType == F) {
        return flagships[attackingAlien].getRect().y;
    }
    return -1;
}

void Model::moveAttackingAlien() {
    if((attackingAlien%10) < 5) {
        if(attackingAlienType == G) {
            greenAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::LEFT);
        } else if(attackingAlienType == B) {
            blueAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::LEFT);
        } else if(attackingAlienType == R) {
            redAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::LEFT);
        } else if(attackingAlienType == F) {
            flagships[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::LEFT);
        }
    } else {
        if(attackingAlienType == G) {
            greenAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::RIGHT);
        } else if(attackingAlienType == B) {
            blueAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::RIGHT);
        } else if(attackingAlienType == R) {
            redAliens[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::RIGHT);
        } else if(attackingAlienType == F) {
            flagships[attackingAlien].moveAttackingAlien(galaxip.getX(), true, Alien::Direction::RIGHT);
        }

    }
}

void Model::checkExplosions() {
    for(int i = 0; i < 60; i++) {
        if(greenAliens[i].getDyingAnimationCounter() > 0) {
            if(greenAliens[i].getDyingAnimationCounter() == 1) {
                greenAliens[i].setDyingAnimationLast();
                greenAliens[i].increaseDyingAnimationCounter();
            } else if(greenAliens[i].getDyingAnimationCounter() == 2 && greenAliens[i].getDyingAnimationLast() > 50) {
                greenAliens[i].setDyingAnimationLast();
                greenAliens[i].increaseDyingAnimationCounter();
            } else if(greenAliens[i].getDyingAnimationCounter() == 3 && greenAliens[i].getDyingAnimationLast() > 50) {
                greenAliens[i].setDyingAnimationCounter(0);
            }
        }
        if(blueAliens[i].getDyingAnimationCounter() > 0) {
            if(blueAliens[i].getDyingAnimationCounter() == 1) {
                blueAliens[i].setDyingAnimationLast();
                blueAliens[i].increaseDyingAnimationCounter();
            } else if(blueAliens[i].getDyingAnimationCounter() == 2 && blueAliens[i].getDyingAnimationLast() > 50) {
                blueAliens[i].setDyingAnimationLast();
                blueAliens[i].increaseDyingAnimationCounter();
            } else if(blueAliens[i].getDyingAnimationCounter() == 3 && blueAliens[i].getDyingAnimationLast() > 50) {
                blueAliens[i].setDyingAnimationCounter(0);
            }
        }
        if(redAliens[i].getDyingAnimationCounter() > 0) {
            if(redAliens[i].getDyingAnimationCounter() == 1) {
                redAliens[i].setDyingAnimationLast();
                redAliens[i].increaseDyingAnimationCounter();
            } else if(redAliens[i].getDyingAnimationCounter() == 2 && redAliens[i].getDyingAnimationLast() > 50) {
                redAliens[i].setDyingAnimationLast();
                redAliens[i].increaseDyingAnimationCounter();
            } else if(redAliens[i].getDyingAnimationCounter() == 3 && redAliens[i].getDyingAnimationLast() > 50) {
                redAliens[i].setDyingAnimationCounter(0);
            }
        }
        if(flagships[i].getDyingAnimationCounter() > 0) {
            if(flagships[i].getDyingAnimationCounter() == 1) {
                flagships[i].setDyingAnimationLast();
                flagships[i].increaseDyingAnimationCounter();
            } else if(flagships[i].getDyingAnimationCounter() == 2 && flagships[i].getDyingAnimationLast() > 50) {
                flagships[i].setDyingAnimationLast();
                flagships[i].increaseDyingAnimationCounter();
            } else if(flagships[i].getDyingAnimationCounter() == 3 && flagships[i].getDyingAnimationLast() > 50) {
                flagships[i].setDyingAnimationCounter(0);
            }
        }
    }
    if(galaxip.getDyingAnimationCounter() > 0) {
        if(galaxip.getDyingAnimationCounter() == 1) {
            galaxip.setDyingAnimationLast();
            galaxip.increaseDyingAnimationCounter();
        } else if(galaxip.getDyingAnimationCounter() == 2 && galaxip.getDyingAnimationLast() > 100) {
            galaxip.setDyingAnimationLast();
            galaxip.increaseDyingAnimationCounter();
        } else if(galaxip.getDyingAnimationCounter() == 3 && galaxip.getDyingAnimationLast() > 100) {
            galaxip.setDyingAnimationCounter(0);
            if(galaxip.getLives() == 0) {
                checkGameOver();
            }
        }
    }
}

void Model::checkForNewAttack() {
    if(!alienInAttack && SDL_GetTicks() - lastAttack > 2000) {
        lastAttack = SDL_GetTicks();
        getNewAttacker();
    }
}

int Model::getNewAttacker() {
    int newAttacker = -1;
    for(int i = 59; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 50; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 58; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 51; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 57; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 52; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 56; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 53; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 55; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    for(int i = 54; i >= 0; i = i - 10) {
        newAttacker = getNewAttackingAlien(i);
        if(newAttacker != -1) {
            return newAttacker;
        }
    }
    return newAttacker;
}

int Model::getNewAttackingAlien(int i) {
    if(greenAliens[i].isInGame() && greenAliens[i].isAlive()) {
        greenAliens[i].setAttackMode(true);
        alienInAttack = true;
        attackingAlien = i;
        attackingAlienType = G;
        return i;
    } else if (blueAliens[i].isInGame() && blueAliens[i].isAlive()) {
        blueAliens[i].setAttackMode(true);
        alienInAttack = true;
        attackingAlien = i;
        attackingAlienType = B;
        return i;
    } else if (redAliens[i].isInGame() && redAliens[i].isAlive()) {
        redAliens[i].setAttackMode(true);
        alienInAttack = true;
        attackingAlien = i;
        attackingAlienType = R;
        return i;
    } else if (flagships[i].isInGame() && flagships[i].isAlive()) {
        flagships[i].setAttackMode(true);
        alienInAttack = true;
        attackingAlien = i;
        attackingAlienType = F;
        return i;
    }
    return -1;
}

void Model::checkGameOver() {
    setGameOver(true);
    initAliens();
    galaxip.setLives(3);
    galaxip.setX(240);
    resetPoints();
    lastAttack = SDL_GetTicks();
    alienInAttack = false;
}

void Model::setGameOver(bool value) {
    gameOver = value;
}

bool Model::isGameOver() {
    return gameOver;
}

void Model::checkIfAllAliensAreDead() {
    bool allDead = true;
    for(int i = 0; i < 60; i++) {
        if(greenAliens[i].isInGame() && greenAliens[i].isAlive()) {
            allDead = false;
        }
        if(blueAliens[i].isInGame() && blueAliens[i].isAlive()) {
            allDead = false;
        }
        if(redAliens[i].isInGame() && redAliens[i].isAlive()) {
            allDead = false;
        }
        if(flagships[i].isInGame() && flagships[i].isAlive()) {
            allDead = false;
        }
    }
    if(allDead) {
        initAliens();
        lastAttack = SDL_GetTicks();
    }
}