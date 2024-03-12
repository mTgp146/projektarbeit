#include "alien.h"
#include <cmath>
#include <cstdio>

Alien::Alien() {
  rect.w = 22;
  rect.h = 11;
  rect.x = 110;
  realX = 110;
  rect.y = 143;
  realY = 143;
  lastUpdate = SDL_GetTicks();
}

SDL_Rect Alien::getRect() const {
  return rect;
}

void Alien::setX(int x) {
  rect.x = x;
  realX = x;
}

void Alien::setY(int y) {
  rect.y = y;
  realY = y;
}

bool Alien::isAlive() const {
  return alive;
}

void Alien::setAlive(bool alive) {
  this->alive = alive;
}

void Alien::changeDirection() {
  if(direction == LEFT) {
    direction = RIGHT;
  } else {
    direction = LEFT;
  }
}

Alien::Direction Alien::getDirection() const {
  return direction;
}

void Alien::setLastUpdate() {
  lastUpdate = SDL_GetTicks();
}

void Alien::setLastAttackUpdate() {
  lastAttackUpdate = SDL_GetTicks();
}

void Alien::moveAlien(int galaxipPos, Direction dir) {
  int dt = SDL_GetTicks() - lastUpdate;
  moveAlienAlongXAxis(dt);
  if(attackMode) {
    moveAttackingAlien(galaxipPos, false, dir);
    rect.x = (int)attackX;
    rect.y = (int)attackY;
  } else {
    setLastAttackUpdate();
    rect.x = (int)realX;
    rect.y = (int)realY;
  }
  if(returnMode && realY < initialY) {
    realY = realY + 0.3 * dt;
    rect.y = (int)realY;
  } else if(returnMode && realY >= initialY) {
    returnMode = false;
    realY = initialY;
    rect.y = (int)realY;
  }
  lastUpdate = SDL_GetTicks();
}

void Alien::moveAttackingAlien(int galaxipPos, bool callFromModel, Direction dir) {
    int dtA = SDL_GetTicks() - lastAttackUpdate;
    if(!isMovingToGalaxip && !isMovingToMiddle && ((dir == Direction::RIGHT && attackX < attackStartX+65) || (dir == Direction::LEFT && attackX > attackStartX-65))) {
      moveInCircle(dtA, dir);
    } else if(((dir == Direction::LEFT && attackX - middleOfScreen < -1.0f) || (dir == Direction::RIGHT && attackX - middleOfScreen > 1.0f)) && isMovingToGalaxip == false) {
      isMovingToMiddle = true;
      moveToMiddle(dtA, dir);
      moveToGalaxipStartX = attackX;
      attackStartY = attackY;
      galaxipPositionAtStartOfAttack = galaxipPos;
    } else {
      isMovingToGalaxip = true;
      isMovingToMiddle = false;
      moveAlienToGalaxip(dtA);
    }
  lastAttackUpdate = SDL_GetTicks();
  if(callFromModel) {
    rect.x = (int)attackX;
    rect.y = (int)attackY;
  }
}

void Alien::moveAlienAlongXAxis(int dt) {
  if(direction == LEFT) {
    realX = realX - 0.02327 * dt;
  } else {
    realX = realX + 0.02327 * dt;
  }
}

int Alien::getTextureNumber() {
  return textureNumber;
}

void Alien::setTextureNumber(int texNum) {
  textureNumber = texNum;
}

void Alien::setAttackMode(bool attackMode) {
  this->attackMode = attackMode;
  if(attackMode) {
    attackStartX = rect.x;
    attackX = rect.x;
  } else {
    isMovingToGalaxip = false;
    isMovingToMiddle = false;
    attackY = realY;
    attackX = realX;
  }
}

bool Alien::isInAttackMode() const {
  return attackMode;
}

void Alien::setInGame(bool inGame) {
  this->inGame = inGame;
}

bool Alien::isInGame() const {
  return inGame;
}

void Alien::setPositionInFormation(int position) {
  rect.x = 110+(position%10)*30;
  realX = rect.x;
  rect.y = 86 + 19*((position/10));
  realY = rect.y;
  attackX = rect.x;
  attackY = rect.y;
  attackStartX = (float)rect.x;
  attackStartY = (float)rect.y;
  initialY = (float)rect.y;
}

void Alien::moveInCircle(int dt, Direction dir) {
  if(dir == LEFT) {
    attackX = attackX - 0.035 * dt;
    attackY = attackY + 1.0 * sin(0.09*(attackX-attackStartX));
  } else {
    attackX = attackX + 0.035 * dt;
    attackY = attackY - 1.0 * sin(0.09*(attackX-attackStartX));
  }
}

void Alien::moveToMiddle(int dt, Direction dir) {
  if(dir == LEFT) {
    attackX = attackX - 0.0007 * dt * (attackStartX - middleOfScreen);
  } else {
    attackX = attackX + 0.0007 * dt * (middleOfScreen - attackStartX);
  }
  if((attackY - realY) <= 0) {
    attackY = attackY + 0.1 * dt;
  } else {
    attackY = attackY + 2.0 * dt * (1/((attackY - realY)+10));
  }
}

void Alien::moveAlienToGalaxip(int dt) {
  attackX = attackX + 0.00053 * dt * (float(galaxipPositionAtStartOfAttack) - middleOfScreen);
  attackY = attackY + 0.0005 * dt * (heightOfGalaxip - attackStartY);
}

bool Alien::isIsMovingToMiddle() const {
  return isMovingToMiddle;
}

int Alien::getDyingAnimationCounter() const {
  return dyingAnimationCounter;
}

void Alien::increaseDyingAnimationCounter() {
  this->dyingAnimationCounter = dyingAnimationCounter + 1;
}

int Alien::getDyingAnimationLast() const {
  return dyingAnimationLast;
}

void Alien::setDyingAnimationLast() {
  dyingAnimationLast = SDL_GetTicks();
}

void Alien::setDyingAnimationCounter(int dyingAnimationCounter) {
  this->dyingAnimationCounter = dyingAnimationCounter;
}

void Alien::setReturnMode(bool returnMode) {
  this->returnMode = returnMode;
  realY = 0.0f;
  rect.y = 0;
}

bool Alien::isReturnMode() const {
  return returnMode;
}
