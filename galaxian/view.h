#include "controller.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class View {

  public:
    int init();
    void render();
    void exit();

  private:
    const int WIDTH = 448;
    const int HEIGHT = 512;
    double m_galaxip_x = 208.0;
    double m_galaxip_y = 284.0;
    SDL_Rect galaxip_rect = SDL_Rect();
    SDL_Texture* galaxip_tex;
    SDL_Surface* galaxip_sur;
    SDL_Renderer* renderer;
    SDL_Window *window;

};
