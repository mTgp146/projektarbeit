#include "red_alien.h"

void RedAlien::setPositionInFormation(int position) {
  rect.x = 170+(position*30);
  realX = rect.x;
  rect.y = 105;
}
