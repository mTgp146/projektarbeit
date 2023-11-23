#include "controller.h"
#include <iostream>

/*
mingw32-make
cmake -G "MinGW Makefiles" .
*/

int main( int argc, char *argv[] ) {
    
    Model model{};
    View view = View{model};
    Controller controller = Controller{model, view};
    view.init();
    controller.init();
    controller.mainLoop();
    
    return EXIT_SUCCESS;
}
