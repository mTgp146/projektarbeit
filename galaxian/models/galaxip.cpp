#include "galaxip.h"

Galaxip::Galaxip() {
  setX(208);
  setY(384);
  rect.w = 32;
  rect.h = 32;
}

int Galaxip::getX() const {
  return rect.x;
}

void Galaxip::setX(int x) {
  rect.x = x;
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

void Galaxip::moveGalaxip(Direction direction) {
  if (direction == LEFT) {
    rect.x = rect.x - 2;
  } else {
    rect.x = rect.x + 2;
  }
}