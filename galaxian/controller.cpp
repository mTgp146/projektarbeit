#include "controller.h"
#include <iostream>
#include <chrono>
#include <thread>

Controller::Controller(Model &model, View &view) : model(model), view(view) {}

void Controller::mainLoop() {
    
    using namespace std::this_thread; //sleep_for
    using namespace std::chrono_literals; //ms

    while (true) {
        view.render();
        handleUserInput();
        gameActions();
        if(SDL_PollEvent(&windowEvent)) {
            if(SDL_QUIT == windowEvent.type) {
                view.exit();
                break; 
                }
        }
        //tickrate anpassbar
        sleep_for(10ms);
    }
}

void Controller::init() {
    model.initAliens();
}

void Controller::gameActions() {
    model.gameActions();
}

void Controller::handleUserInput() {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) {
        model.moveGalaxip(Galaxip::Direction::LEFT);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        model.moveGalaxip(Galaxip::Direction::RIGHT);
    }
    if (state[SDL_SCANCODE_D]) {
        model.shotByGalaxip();
    }
}