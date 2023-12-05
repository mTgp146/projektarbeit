#include "backgroundParticle.h"

BackgroundParticle::BackgroundParticle(int x, COLOR color) {
  rect.x = x;
  rect.y = 0;
  rect.w = 1;
  rect.h = 1;
  this->color = color;
}

void BackgroundParticle::update() {
  rect.y = rect.y + 1;
  if (rect.y > 512) {
    rect.y = 0;
  }
}

SDL_Rect BackgroundParticle::getRect() const {
  return rect;
}