#include <SDL2/SDL.h>

/**
 * The Galaxip class represents the player's ship.
*/
class Galaxip {
public:
  Galaxip();
  /**
   * The Direction enum represents the direction the Galaxip is moving.
  */
  enum Direction { LEFT, RIGHT };
  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  SDL_Rect getRect() const;
  /**
   * Sets the last update time to the current time.
  */
  void setLastUpdate();
  /**
   * Moves the Galaxip in the game.
   * @param direction The direction in which the Galaxip is moving.
  */
  void moveGalaxip(Direction direction);

private:
  /**
   * The real x coordinate of the Galaxip.
  */
  float realX = 240.0f;
  SDL_Rect rect = SDL_Rect();
  int lastUpdate;
};
