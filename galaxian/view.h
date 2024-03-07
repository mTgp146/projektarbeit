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
    void renderAliens();
    void renderGreenAlien(int pos);
    void renderBlueAlien(int pos);
    void renderRedAlien(int pos);
    void renderFlagship(int pos);
    void renderBackground();
    void exit();

  private:
    const int WIDTH = 512;
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
    SDL_Texture* blue_alien1_tex;
    SDL_Surface* blue_alien1_sur;
    SDL_Texture* blue_alien2_tex;
    SDL_Surface* blue_alien2_sur;
    SDL_Texture* blue_alien3_tex;
    SDL_Surface* blue_alien3_sur;
    SDL_Texture* red_alien1_tex;
    SDL_Surface* red_alien1_sur;
    SDL_Texture* red_alien2_tex;
    SDL_Surface* red_alien2_sur;
    SDL_Texture* red_alien3_tex;
    SDL_Surface* red_alien3_sur;
    SDL_Texture* flagship_tex;
    SDL_Surface* flagship_sur;
    SDL_Renderer* renderer;
    SDL_Window *window;
    Model &model;

};
