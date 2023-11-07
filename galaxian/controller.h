#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "view.h"

class Controller {
public:
    Controller();
    void setModel(Model* model);
    void setView(View* view);
    void start();
    void stop();
    void update();
    void handleEvent(SDL_Event& event);
    void handleKeyPress(SDL_Keycode& key);
    void handleKeyRelease(SDL_Keycode& key);
    void handleQuit();

private:
    Model* model;
    View* view;
    bool left_pressed;
    bool right_pressed;
};