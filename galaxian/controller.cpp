#include "controller.h"
#include <iostream>

Controller::Controller(Model &model) : model(model) {}

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