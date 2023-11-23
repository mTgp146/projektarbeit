#include <SDL2/SDL.h>

class Galaxip {
public:
  Galaxip();
  enum Direction { LEFT, RIGHT };
  int getX() const;
  void setX(int x);

  int getY() const;
  void setY(int y);

  SDL_Rect getRect() const;

  void setLastUpdate();
  void moveGalaxip(Direction direction);

private:
  float realX = 240.0f;
  SDL_Rect rect = SDL_Rect();
  int lastUpdate;
};
