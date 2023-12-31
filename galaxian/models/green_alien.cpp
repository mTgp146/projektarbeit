#include "green_alien.h"

void GreenAlien::setPositionInFormation(int position) {
  rect.x = 110+(position%10)*30;
  realX = rect.x;
  rect.y = 143 + 19*((position/10));
}
