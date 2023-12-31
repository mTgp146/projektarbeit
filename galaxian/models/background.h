#include "backgroundParticle.h"
#include <array>

class Background {
public:
  Background();
  void update();
  std::array<BackgroundParticle, 128> getParticles() const;

private:
  std::array<BackgroundParticle, 128> particles = {};
};