#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "view.h"

/**
 * The Controller class is responsible for handling user input and updating the game state.
 * IT contains the main loop of the game.
*/
class Controller {
    
    public:
        /**
         * Constructor of the Controller class.
         * @param model The model of the game.
         * @param view The view of the game.
        */
        Controller(Model &model, View &view);
        /**
         * The main loop of the game.
        */
        void mainLoop();
        /**
         * Initializes the game.
        */
        void init();
        /**
         * Performs the game actions.
        */
        void gameActions();
        /**
         * Handles the user inputs.
        */
        void handleUserInput();
    
    private:
        Model &model;
        View &view;
        SDL_Event windowEvent;
};
