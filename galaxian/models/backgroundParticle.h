#include <SDL2/SDL.h>

class BackgroundParticle {

public:
  enum COLOR { RED, GREEN, BLUE };
  BackgroundParticle();
  void setValues(int x, int y, COLOR color);
  void update();
  SDL_Rect getRect() const;
  SDL_Color getColor() const;

private:
  SDL_Rect rect = SDL_Rect();
  SDL_Color color = SDL_Color();
  float realY = 0.0f;
};