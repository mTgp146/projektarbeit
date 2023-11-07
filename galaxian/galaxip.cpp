#include "galaxip.h"

Galaxip::Galaxip() {
  x = 0;
  y = 0;
}

int Galaxip::getX() const {
  return x;
}

void Galaxip::setX(int x) {
  this->x = x;
}

int Galaxip::getY() const {
  return y;
}

void Galaxip::setY(int y) {
  this->y = y;
}

void Galaxip::moveLeft() {
  x = x - 1;
}

void Galaxip::moveRight() {
  x = x + 1;
}