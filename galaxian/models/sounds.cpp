#include "sounds.h"
#include <iostream>

Sounds::Sounds() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL Audio could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        } else {
            this->shot = Mix_LoadWAV("sounds/shot.wav");
            if (shot == NULL) {
                std::cout << "Failed to load shot sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
            }
            this->explosion = Mix_LoadWAV("sounds/explosion.wav");
            if (explosion == NULL) {
                std::cout << "Failed to load explosion sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
            }
            this->background = Mix_LoadMUS("sounds/background.wav");
            if (background == NULL) {
                std::cout << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << std::endl;
            }
        }
    }
}

void Sounds::playShot() {
    Mix_PlayChannel(-1, this->shot, 0);
}

void Sounds::playExplosion() {
    Mix_PlayChannel(-1, this->explosion, 0);
}

void Sounds::playBackground() {
    Mix_PlayMusic(this->background, -1);
}

void Sounds::stopBackground() {
    Mix_HaltMusic();
}

Sounds::~Sounds() {
    Mix_FreeChunk(this->shot);
    Mix_FreeMusic(this->background);
    Mix_Quit();
}