#include "flagship.h"

void Flagship::setPositionInFormation(int position) {
  rect.x = 110+(position*30);
  realX = rect.x;
  rect.y = 86;
  rect.h += 2;
}
