#include "view.h"
#include <iostream>

View::View(Model &model) : model(model) {}

void View::render() {
    SDL_RenderClear(renderer);

    renderBackground();
	renderGalaxip();
    renderGalaxipProjectile();
    renderGreenAliens();
    renderBlueAliens();
    renderRedAliens();
    renderFlagships();

	SDL_RenderPresent(renderer);
}

void View::renderGalaxip() {
    SDL_Rect galaxip_rect = model.getGalaxip().getRect();
    SDL_RenderCopy(renderer, galaxip_tex, NULL, &galaxip_rect);

    /*  rotate by 45 degrees
    SDL_Point center = SDL_Point();
    center.x = 16;
    center.y = 16;
    SDL_RenderCopyEx(renderer, galaxip_tex, NULL, &galaxip_rect, 45.0, &center, SDL_FLIP_NONE);
    */
}

void View::renderGalaxipProjectile() {
    SDL_Rect projectile_galaxip_rect = model.getGalaxipProjectile().getRect();
    SDL_RenderCopy(renderer, projectile_galaxip_tex, NULL, &projectile_galaxip_rect);
}

void View::renderGreenAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getGreenAlien(i).isAlive() && model.getGreenAlien(i).isInGame())	{
            SDL_Rect green_alien_rect = model.getGreenAlien(i).getRect();
            if(model.getGreenAlien(i).getTextureNumber() == 1) {
                SDL_RenderCopy(renderer, green_alien1_tex, NULL, &green_alien_rect);
            } else if(model.getGreenAlien(i).getTextureNumber() == 2) {
                SDL_RenderCopy(renderer, green_alien2_tex, NULL, &green_alien_rect);
            } else {
                SDL_RenderCopy(renderer, green_alien3_tex, NULL, &green_alien_rect);
            }
        }
    }
}

void View::renderBlueAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getBlueAlien(i).isAlive() && model.getBlueAlien(i).isInGame()) {
            SDL_Rect blue_alien_rect = model.getBlueAlien(i).getRect();
            if(model.getBlueAlien(i).getTextureNumber() == 1) {
                SDL_RenderCopy(renderer, blue_alien1_tex, NULL, &blue_alien_rect);
            } else if(model.getBlueAlien(i).getTextureNumber() == 2) {
                SDL_RenderCopy(renderer, blue_alien2_tex, NULL, &blue_alien_rect);
            } else {
                SDL_RenderCopy(renderer, blue_alien3_tex, NULL, &blue_alien_rect);
            }
        }
    }
}

void View::renderRedAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getRedAlien(i).isAlive() && model.getRedAlien(i).isInGame()) {
            SDL_Rect red_alien_rect = model.getRedAlien(i).getRect();
            if(model.getRedAlien(i).getTextureNumber() == 1) {
                SDL_RenderCopy(renderer, red_alien1_tex, NULL, &red_alien_rect);
            } else if(model.getRedAlien(i).getTextureNumber() == 2) {
                SDL_RenderCopy(renderer, red_alien2_tex, NULL, &red_alien_rect);
            } else {
                SDL_RenderCopy(renderer, red_alien3_tex, NULL, &red_alien_rect);
            }
        }
    }
}

void View::renderFlagships() {
    for (int i = 0; i < 60; i++) {
        if(model.getFlagship(i).isAlive() && model.getFlagship(i).isInGame()) {
            SDL_Rect flagship_rect = model.getFlagship(i).getRect();
            SDL_RenderCopy(renderer, flagship_tex, NULL, &flagship_rect);
        }
    }
}

void View::renderBackground() {
    std::array<BackgroundParticle, 128> backgroundParticles = model.getBackgroundParticles();
    for (int i = 0; i < 128; i++) {
        if(backgroundParticles[i].getRect().y % 20 < 10) {
            SDL_Rect backgroundParticle_rect = backgroundParticles[i].getRect();
            SDL_Color backgroundParticle_color = backgroundParticles[i].getColor();
            SDL_SetRenderDrawColor(renderer, backgroundParticle_color.r, backgroundParticle_color.g, backgroundParticle_color.b, backgroundParticle_color.a);
            SDL_RenderFillRect(renderer, &backgroundParticle_rect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
    }
}

void View::exit() {
    SDL_DestroyTexture(galaxip_tex);
    SDL_DestroyTexture(projectile_galaxip_tex);
    SDL_DestroyTexture(green_alien1_tex);
    SDL_DestroyTexture(green_alien2_tex);
    SDL_DestroyTexture(green_alien3_tex);
    SDL_DestroyTexture(blue_alien1_tex);
    SDL_DestroyTexture(blue_alien2_tex);
    SDL_DestroyTexture(blue_alien3_tex);
    SDL_DestroyTexture(red_alien1_tex);
    SDL_DestroyTexture(red_alien2_tex);
    SDL_DestroyTexture(red_alien3_tex);
    SDL_DestroyTexture(flagship_tex);

	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int View::init() {
    SDL_Init( SDL_INIT_EVERYTHING );

    if (IMG_Init(IMG_INIT_PNG) == 0) {
	    std::cout << "Error SDL2_image Initialization";
	    return 2;
    }

    window = SDL_CreateWindow( "Galaxian", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window ) {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
	    std::cout << "Error renderer creation";
	    return 4;
    }

    galaxip_sur = IMG_Load("images/Galaxip.png");
    galaxip_tex = SDL_CreateTextureFromSurface(renderer, galaxip_sur);
    SDL_FreeSurface(galaxip_sur);

    projectile_galaxip_sur = IMG_Load("images/Projectile_Galaxip.png");
    projectile_galaxip_tex = SDL_CreateTextureFromSurface(renderer, projectile_galaxip_sur);
    SDL_FreeSurface(projectile_galaxip_sur);

    green_alien1_sur = IMG_Load("images/Green_Alien1.png");
    green_alien1_tex = SDL_CreateTextureFromSurface(renderer, green_alien1_sur);
    SDL_FreeSurface(green_alien1_sur);

    green_alien2_sur = IMG_Load("images/Green_Alien2.png");
    green_alien2_tex = SDL_CreateTextureFromSurface(renderer, green_alien2_sur);
    SDL_FreeSurface(green_alien2_sur);

    green_alien3_sur = IMG_Load("images/Green_Alien3.png");
    green_alien3_tex = SDL_CreateTextureFromSurface(renderer, green_alien3_sur);
    SDL_FreeSurface(green_alien3_sur);

    blue_alien1_sur = IMG_Load("images/Blue_Alien1.png");
    blue_alien1_tex = SDL_CreateTextureFromSurface(renderer, blue_alien1_sur);
    SDL_FreeSurface(blue_alien1_sur);

    blue_alien2_sur = IMG_Load("images/Blue_Alien2.png");
    blue_alien2_tex = SDL_CreateTextureFromSurface(renderer, blue_alien2_sur);
    SDL_FreeSurface(blue_alien2_sur);

    blue_alien3_sur = IMG_Load("images/Blue_Alien3.png");
    blue_alien3_tex = SDL_CreateTextureFromSurface(renderer, blue_alien3_sur);
    SDL_FreeSurface(blue_alien3_sur);

    red_alien1_sur = IMG_Load("images/Red_Alien1.png");
    red_alien1_tex = SDL_CreateTextureFromSurface(renderer, red_alien1_sur);
    SDL_FreeSurface(red_alien1_sur);

    red_alien2_sur = IMG_Load("images/Red_Alien2.png");
    red_alien2_tex = SDL_CreateTextureFromSurface(renderer, red_alien2_sur);
    SDL_FreeSurface(red_alien2_sur);

    red_alien3_sur = IMG_Load("images/Red_Alien3.png");
    red_alien3_tex = SDL_CreateTextureFromSurface(renderer, red_alien3_sur);
    SDL_FreeSurface(red_alien3_sur);

    flagship_sur = IMG_Load("images/Flagship.png");
    flagship_tex = SDL_CreateTextureFromSurface(renderer, flagship_sur);
    SDL_FreeSurface(flagship_sur);

    return 0;

}
