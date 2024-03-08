#include <SDL2/SDL.h>

/**
 * The BackgroundParticle class represents a colored particle in the background of the game.
*/
class BackgroundParticle {

public:
  /**
   * The COLOR enum represents the color of the particle.
  */
  enum COLOR { RED, GREEN, BLUE };
  BackgroundParticle();
  /**
   * Sets the values of the particle.
   * @param x The x coordinate of the particle.
   * @param y The y coordinate of the particle.
   * @param color The color of the particle.
  */
  void setValues(int x, int y, COLOR color);
  /**
   * Updates the particle.
  */
  void update();
  SDL_Rect getRect() const;
  SDL_Color getColor() const;

private:
  SDL_Rect rect = SDL_Rect();
  SDL_Color color = SDL_Color();
  /**
   * The real y coordinate of the particle.
   * This is used to update the particle every frame by a real amount and not by a rounded amount.
  */
  float realY = 0.0f;
};