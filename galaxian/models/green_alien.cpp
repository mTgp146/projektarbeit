#include "green_alien.h"

GreenAlien::GreenAlien() {
  rect.w = 28;
  rect.h = 16;
  rect.x = 20;
  rect.y = 32;
}

void GreenAlien::setPositionInFormation(int position) {
  rect.x = 30+(position%10)*40;
  rect.y = 100 + 32*((position/10)+1);
}

SDL_Rect GreenAlien::getRect() const {
  return rect;
}

void GreenAlien::setX(int x) {
  rect.x = x;
}

void GreenAlien::setY(int y) {
  rect.y = y;
}

void GreenAlien::moveGreenAlien() {
  
}

bool GreenAlien::isAlive() const {
  return alive;
}

void GreenAlien::setAlive(bool alive) {
  this->alive = alive;
}

