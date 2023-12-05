#include <list>
#include "backgroundParticle.h"

class Background {
public:
  Background();
  void update();
  std::list<BackgroundParticle> getParticles() const;

private:
  std::list<BackgroundParticle> particles;
};