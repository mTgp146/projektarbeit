#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "model.h"

class View {

  public:
    View(Model &model);
    int init();
    void render();
    void exit();

  private:
    const int WIDTH = 448;
    const int HEIGHT = 512;
    SDL_Texture* galaxip_tex;
    SDL_Surface* galaxip_sur;
    SDL_Texture* projectile_galaxip_tex;
    SDL_Surface* projectile_galaxip_sur;
    SDL_Renderer* renderer;
    SDL_Window *window;
    Model &model;

};
