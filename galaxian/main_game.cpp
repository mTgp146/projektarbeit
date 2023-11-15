#include "controller.h"
#include "SDL2/SDL.h"
#include <iostream>
#include <chrono>
#include <thread>


int main( int argc, char *argv[] ) {
    using namespace std::this_thread; //sleep_for
    using namespace std::chrono_literals; //ms

    Model model{};
    View view = View{model};
    Controller controller = Controller{model};
    SDL_Event windowEvent;
    view.init();
    while (true) {
        view.render();
        controller.handleUserInput();
        controller.gameActions();
        if(SDL_PollEvent(&windowEvent)) {
            if(SDL_QUIT == windowEvent.type) {
                view.exit();
                break; 
                }
        }
        sleep_for(10ms);
    }
    return EXIT_SUCCESS;
}
