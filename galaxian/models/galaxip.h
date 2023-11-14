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

  void moveGalaxip(Direction direction);

private:
  SDL_Rect rect = SDL_Rect();
};
