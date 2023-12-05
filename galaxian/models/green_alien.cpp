#include "green_alien.h"

GreenAlien::GreenAlien() {
  rect.w = 22;
  rect.h = 11;
  rect.x = 110;
  realX = 110;
  rect.y = 143;
  lastUpdate = SDL_GetTicks();
}

void GreenAlien::setPositionInFormation(int position) {
  rect.x = 110+(position%10)*30;
  realX = rect.x;
  rect.y = 143 + 19*((position/10));
}

SDL_Rect GreenAlien::getRect() const {
  return rect;
}

void GreenAlien::setX(int x) {
  rect.x = x;
  realX = x;
}

void GreenAlien::setY(int y) {
  rect.y = y;
}

bool GreenAlien::isAlive() const {
  return alive;
}

void GreenAlien::setAlive(bool alive) {
  this->alive = alive;
}

void GreenAlien::changeDirection() {
  if(direction == LEFT) {
    direction = RIGHT;
  } else {
    direction = LEFT;
  }
}

GreenAlien::Direction GreenAlien::getDirection() const {
  return direction;
}

void GreenAlien::setLastUpdate() {
  lastUpdate = SDL_GetTicks();
}

void GreenAlien::moveGreenAlienAlongXAxis() {
  int dT = SDL_GetTicks() - lastUpdate;
  if(direction == LEFT) {
    realX = realX - 0.02327 * dT;
  } else {
    realX = realX + 0.02327 * dT;
  }
  rect.x = (int)realX;
  lastUpdate = SDL_GetTicks();
}

int GreenAlien::getTextureNumber() {
  return textureNumber;
}

void GreenAlien::setTextureNumber(int texNum) {
  textureNumber = texNum;
}