#include "view.h"
//#include "controller.h"
//#include "model.h"
#include "SDL2/SDL.h"
#include <iostream>



int main( int argc, char *argv[] ) {
    //Model model{};
    //Controller controller = Controller{};
    View view = View{};
    SDL_Event windowEvent;
    view.init();
    while (true) {
        view.render();
        //controller.handleUserInput();
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type ) {
                view.exit();
                break; 
                }
        } 
    }
    return EXIT_SUCCESS;
}
