#include "controller.h"
#include <iostream>
#include <cmath>

Controller::Controller(Model &model, View &view) : model(model), view(view) {}

void Controller::mainLoop() {
    while (true) {
        Uint64 start = SDL_GetPerformanceCounter();

        // game loop
        view.render();
        handleUserInput();
        gameActions();

        // Cap to 60 FPS
        Uint64 end = SDL_GetPerformanceCounter();
	    float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        if(elapsedMS < 16.666f) {
            SDL_Delay(floor(16.666f - elapsedMS));
        }

        // stop game if window is closed
        if(SDL_PollEvent(&windowEvent)) {
            if(SDL_QUIT == windowEvent.type) {
                view.exit();
                break; 
                }
        }
    }
}

void Controller::init() {
    model.initAliens();
    model.setHighscore();
    model.startMusic();
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
    model.setGalaxipDT();
    if (state[SDL_SCANCODE_X]) {
        model.shotByGalaxip();
    }
}