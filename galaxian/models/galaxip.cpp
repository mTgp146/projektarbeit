#include "galaxip.h"

Galaxip::Galaxip() {
  setX(240);
  setY(448);
  rect.w = 32;
  rect.h = 32;
  lastUpdate = SDL_GetTicks();
}

int Galaxip::getX() const {
  return rect.x;
}

void Galaxip::setX(int x) {
  rect.x = x;
  realX = x;
}

int Galaxip::getY() const {
  return rect.y;
}

void Galaxip::setY(int y) {
  rect.y = y;
}

SDL_Rect Galaxip::getRect() const {
  return rect;
}

void Galaxip::setLastUpdate() {
  lastUpdate = SDL_GetTicks();
}

void Galaxip::moveGalaxip(Direction direction) {
  int dT = SDL_GetTicks() - lastUpdate;

  if (direction == LEFT) {
    if (rect.x <= 10) {
      rect.x = 10;
      realX = 10;
    } else {
      realX = realX - 0.131*dT;
    }
  } else {
    if (rect.x >= 470) {
      rect.x = 470;
      realX = 470;
    } else {
      realX = realX + 0.131*dT;
    }
  }
  rect.x = (int)realX;
}

int Galaxip::getLives() const {
  return lives;
}

bool Galaxip::loseLife() {
  lives--;
  alive = false;
  if (lives == 0) {
    return true;
  }
  return false;
}

bool Galaxip::isAlive() const {
  return alive;
}

void Galaxip::setAlive(bool alive) {
  this->alive = alive;
}

int Galaxip::getDyingAnimationCounter() const {
  return dyingAnimationCounter;
}

void Galaxip::increaseDyingAnimationCounter() {
  this->dyingAnimationCounter = dyingAnimationCounter + 1;
}

int Galaxip::getDyingAnimationLast() const {
  return dyingAnimationLast;
}

void Galaxip::setDyingAnimationLast() {
  dyingAnimationLast = SDL_GetTicks();
}

void Galaxip::setDyingAnimationCounter(int dyingAnimationCounter) {
  this->dyingAnimationCounter = dyingAnimationCounter;
}
