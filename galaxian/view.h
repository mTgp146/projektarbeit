#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "model.h"

/**
 * The View class is responsible for rendering the game state.
 
*/
class View {

  public:
    /**
     * Constructor of the View class.
     * @param model The model of the game.
    */
    View(Model &model);
    /**
     * Initializes the game.
     * It initializes the SDL library, the window and the renderer.
    */
    int init();
    /**
     * Renders the game state.
     * This method is called every frame.
     * It calles the render methods of the different game objects.
    */
    void render();
    void renderGalaxip();
    void renderGalaxipProjectile();
    void renderGreenAliens();
    void renderBlueAliens();
    void renderRedAliens();
    void renderFlagships();
    void renderBackground();
    void renderScore();
    /**
     * Exits the game.
     * It frees the memory used by the textures and the renderer.
    */
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
    SDL_Texture* num_0_tex;
    SDL_Surface* num_0_sur;
    SDL_Texture* num_1_tex;
    SDL_Surface* num_1_sur;
    SDL_Texture* num_2_tex;
    SDL_Surface* num_2_sur;
    SDL_Texture* num_3_tex;
    SDL_Surface* num_3_sur;
    SDL_Texture* num_4_tex;
    SDL_Surface* num_4_sur;
    SDL_Texture* num_5_tex;
    SDL_Surface* num_5_sur;
    SDL_Texture* num_6_tex;
    SDL_Surface* num_6_sur;
    SDL_Texture* num_7_tex;
    SDL_Surface* num_7_sur;
    SDL_Texture* num_8_tex;
    SDL_Surface* num_8_sur;
    SDL_Texture* num_9_tex;
    SDL_Surface* num_9_sur;
    SDL_Renderer* renderer;
    SDL_Window *window;
    Model &model;

};
