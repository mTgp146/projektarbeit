#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "view.h"

class Controller {
    
    public:
        Controller(Model &model);
        void init();
        void gameActions();
        void handleUserInput();
    
    private:
        Model &model;

};
