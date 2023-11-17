#include "green_alien.h"

GreenAlien::GreenAlien() {
  rect.w = 26;
  rect.h = 14;
  rect.x = 20;
  rect.y = 32;
}

void GreenAlien::setPositionInFormation(int position) {
  rect.x = 81+(position%10)*36;
  rect.y = 143 + 23*((position/10));
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

void GreenAlien::moveGreenAlienAlongXAxis() {
  if(direction == LEFT) {
    if(rect.x <= 0) {
      changeDirection();
      rect.x = rect.x + 2;
    } else {
      rect.x = rect.x - 2;
    } 
  } else if(rect.x >= 486) {
    changeDirection();
    rect.x = rect.x - 2;
  } else {
    rect.x = rect.x + 2;
  }
}