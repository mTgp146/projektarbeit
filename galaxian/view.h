#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "model.h"

class View {

  public:
    View(Model &model);
    int init();
    void render();
    void renderGalaxip();
    void renderGalaxipProjectile();
    void renderGreenAliens();
    void exit();

  private:
    const int WIDTH = 448;
    const int HEIGHT = 512;
    SDL_Texture* galaxip_tex;
    SDL_Surface* galaxip_sur;
    SDL_Texture* projectile_galaxip_tex;
    SDL_Surface* projectile_galaxip_sur;
    SDL_Texture* green_alien1_tex;
    SDL_Surface* green_alien1_sur;
    SDL_Texture* green_alien2_tex;
    SDL_Surface* green_alien2_sur;
    SDL_Texture* green_alien3_tex;
    SDL_Surface* green_alien3_sur;
    int tick_counter = 0;
    int green_alien_counter = 0;
    SDL_Renderer* renderer;
    SDL_Window *window;
    Model &model;

};
