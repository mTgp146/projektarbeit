#include <SDL2/SDL.h>

class BackgroundParticle {

public:
  enum COLOR { RED, GREEN, BLUE };
  BackgroundParticle(int x, COLOR color);
  void update();
  SDL_Rect getRect() const;

private:
  SDL_Rect rect = SDL_Rect();
  COLOR color;
}