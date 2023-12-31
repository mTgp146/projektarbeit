#include "alien.h"

Alien::Alien() {
  rect.w = 22;
  rect.h = 11;
  rect.x = 110;
  realX = 110;
  rect.y = 143;
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