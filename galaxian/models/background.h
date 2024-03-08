#include "backgroundParticle.h"
#include <array>

/**
 * The Background class represents the background of the game.
*/
class Background {
public:
  Background();
  /**
   * Updates every particle of the background.
  */
  void update();
  std::array<BackgroundParticle, 128> getParticles() const;

private:
  /**
   * The random particles that make up the background.
  */
  std::array<BackgroundParticle, 128> particles = {};
};