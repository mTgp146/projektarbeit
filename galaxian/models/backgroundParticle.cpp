#include "backgroundParticle.h"

BackgroundParticle::BackgroundParticle() {
  rect.x = 0;
  rect.y = 0;
  rect.w = 2;
  rect.h = 2;
}

void BackgroundParticle::setValues(int x, int y, COLOR color) {
  realY = y;
  rect.x = x;
  rect.y = y;
  if (color == COLOR::RED) {
    this->color = {255, 0, 0, 255};
  } else if (color == COLOR::GREEN) {
    this->color = {0, 255, 0, 255};
  } else {
    this->color = {0, 0, 255, 255};
  }
}

void BackgroundParticle::update() {
  realY = realY + 0.5f;
  rect.y = (int)realY;
  if (rect.y > 512) {
    rect.y = 0;
    realY = 0;
  }
}

SDL_Rect BackgroundParticle::getRect() const {
  return rect;
}

SDL_Color BackgroundParticle::getColor() const {
  return color;
}