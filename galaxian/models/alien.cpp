#include "alien.h"

Alien::Alien(int position) {
  rect.w = 22;
  rect.h = 11;
  rect.x = 110+(position%10)*30;
  realX = rect.x;
  rect.y = 86+(position/10)*19;
  realY = rect.y;
  lastUpdate = SDL_GetTicks();
  type = NONE;
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

void Alien::moveAlien() {
  if(attackMode) {
    moveAttackingAlien();
  } else {
    moveAlienAlongXAxis();
  }
}

void Alien::moveAttackingAlien() {
  int dT = SDL_GetTicks() - lastUpdate;
  realY = realY + 0.02327 * dT;
  rect.y = (int)realY;
  lastUpdate = SDL_GetTicks();
}

void Alien::moveAlienAlongXAxis() {
  int dT = SDL_GetTicks() - lastUpdate;
  if(direction == LEFT) {
    realX = realX - 0.02327 * dT;
  } else {
    realX = realX + 0.02327 * dT;
  }
  rect.x = (int)realX;
  lastUpdate = SDL_GetTicks();
}

int Alien::getTextureNumber() {
  return textureNumber;
}

void Alien::setTextureNumber(int texNum) {
  textureNumber = texNum;
}

void Alien::setAttackMode(bool attackMode) {
  this->attackMode = attackMode;
}

bool Alien::isInAttackMode() const {
  return attackMode;
}

Alien::Type Alien::getType() const {
  return type;
}

void Alien::setType(Type type) {
  this->type = type;
}