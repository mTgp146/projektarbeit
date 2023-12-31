#include "blue_alien.h"

void BlueAlien::setPositionInFormation(int position) {
  rect.x = 140+(position*30);
  realX = rect.x;
  rect.y = 124;
}
