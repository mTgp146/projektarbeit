#include "view.h"
#include <iostream>

View::View(Model &model) : model(model) {}

void View::render() {
    SDL_RenderClear(renderer);

    renderBackground();
	renderGalaxip();
    renderGalaxipProjectile();
    renderAlienProjectiles();
    renderGreenAliens();
    renderBlueAliens();
    renderRedAliens();
    renderFlagships();
    renderScore();
    renderLives();
    renderExplosions();

	SDL_RenderPresent(renderer);
}

void View::renderGalaxip() {
    SDL_Rect galaxip_rect = model.getGalaxip().getRect();
    if(model.getGalaxip().getLives() > 0 && model.getGalaxip().isAlive()) {
        SDL_RenderCopy(renderer, galaxip_tex, NULL, &galaxip_rect);
    }
}

void View::renderGalaxipProjectile() {
    if(model.getGalaxip().isAlive() || model.getGalaxipProjectile().isAlive()) {
        SDL_Rect projectile_galaxip_rect = model.getGalaxipProjectile().getRect();
        SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
        SDL_RenderFillRect(renderer, &projectile_galaxip_rect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
}

void View::renderAlienProjectiles() {
    for(int i = 0; i < 2; i++) {
        if(model.getAlienProjectile(i).isAlive()) {
            SDL_Rect alien_projectile_rect = model.getAlienProjectile(i).getRect();
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &alien_projectile_rect);
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        }
    
    }
}

void View::renderGreenAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getGreenAlien(i).isAlive() && model.getGreenAlien(i).isInGame())	{
            if(model.getGreenAlien(i).isInAttackMode() && model.getGreenAlien(i).isIsMovingToMiddle()) {
                SDL_Rect green_alien_rect = model.getGreenAlien(i).getRect();
                SDL_Point center = SDL_Point();
                center.x = 11;
                center.y = 5;
                if(model.getGreenAlien(i).getTextureNumber() == 1) {
                    SDL_RenderCopyEx(renderer, green_alien1_tex, NULL, &green_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else if(model.getGreenAlien(i).getTextureNumber() == 2) {
                    SDL_RenderCopyEx(renderer, green_alien2_tex, NULL, &green_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else {
                    SDL_RenderCopyEx(renderer, green_alien3_tex, NULL, &green_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                }
            } else {
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
}

void View::renderBlueAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getBlueAlien(i).isAlive() && model.getBlueAlien(i).isInGame()) {
            if(model.getBlueAlien(i).isInAttackMode() && model.getBlueAlien(i).isIsMovingToMiddle()) {
                SDL_Rect blue_alien_rect = model.getBlueAlien(i).getRect();
                SDL_Point center = SDL_Point();
                center.x = 11;
                center.y = 5;
                if(model.getBlueAlien(i).getTextureNumber() == 1) {
                    SDL_RenderCopyEx(renderer, blue_alien1_tex, NULL, &blue_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else if(model.getBlueAlien(i).getTextureNumber() == 2) {
                    SDL_RenderCopyEx(renderer, blue_alien2_tex, NULL, &blue_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else {
                    SDL_RenderCopyEx(renderer, blue_alien3_tex, NULL, &blue_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                }
            } else {
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
}

void View::renderRedAliens() {
    for (int i = 0; i < 60; i++) {
        if(model.getRedAlien(i).isAlive() && model.getRedAlien(i).isInGame()) {
            if(model.getRedAlien(i).isInAttackMode() && model.getRedAlien(i).isIsMovingToMiddle()) {
                SDL_Rect red_alien_rect = model.getRedAlien(i).getRect();
                SDL_Point center = SDL_Point();
                center.x = 11;
                center.y = 5;
                if(model.getRedAlien(i).getTextureNumber() == 1) {
                    SDL_RenderCopyEx(renderer, red_alien1_tex, NULL, &red_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else if(model.getRedAlien(i).getTextureNumber() == 2) {
                    SDL_RenderCopyEx(renderer, red_alien2_tex, NULL, &red_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                } else {
                    SDL_RenderCopyEx(renderer, red_alien3_tex, NULL, &red_alien_rect, 45.0, &center, SDL_FLIP_NONE);
                }
            } else {
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
}

void View::renderFlagships() {
    for (int i = 0; i < 60; i++) {
        if(model.getFlagship(i).isAlive() && model.getFlagship(i).isInGame()) {
            if(model.getFlagship(i).isInAttackMode() && model.getFlagship(i).isIsMovingToMiddle()) {
                SDL_Rect flagship_rect = model.getFlagship(i).getRect();
                SDL_Point center = SDL_Point();
                center.x = 11;
                center.y = 5;
                SDL_RenderCopyEx(renderer, flagship_tex, NULL, &flagship_rect, 45.0, &center, SDL_FLIP_NONE);
            } else {
                SDL_Rect flagship_rect = model.getFlagship(i).getRect();
                SDL_RenderCopy(renderer, flagship_tex, NULL, &flagship_rect);
            }
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

void View::renderScore() {
    int points = model.getPoints();
    int digit = 0;
    int x = 0;
    do {
        digit = points % 10;
        points = points / 10;
        SDL_Rect num_rect = {104 - x, 8, 16, 20};
        if(digit == 0) {
            SDL_RenderCopy(renderer, num_0_tex, NULL, &num_rect);
        } else if(digit == 1) {
            SDL_RenderCopy(renderer, num_1_tex, NULL, &num_rect);
        } else if(digit == 2) {
            SDL_RenderCopy(renderer, num_2_tex, NULL, &num_rect);
        } else if(digit == 3) {
            SDL_RenderCopy(renderer, num_3_tex, NULL, &num_rect);
        } else if(digit == 4) {
            SDL_RenderCopy(renderer, num_4_tex, NULL, &num_rect);
        } else if(digit == 5) {
            SDL_RenderCopy(renderer, num_5_tex, NULL, &num_rect);
        } else if(digit == 6) {
            SDL_RenderCopy(renderer, num_6_tex, NULL, &num_rect);
        } else if(digit == 7) {
            SDL_RenderCopy(renderer, num_7_tex, NULL, &num_rect);
        } else if(digit == 8) {
            SDL_RenderCopy(renderer, num_8_tex, NULL, &num_rect);
        } else {
            SDL_RenderCopy(renderer, num_9_tex, NULL, &num_rect);
        }
        x += 20;
    } while (points > 0	);
}

void View::renderLives() {
    int lives = model.getGalaxip().getLives();
    int x = 20;
    for(int i = 0; i < lives; i++) {
        SDL_Rect galaxip_rect = {WIDTH - x, 8, 16, 16};
        SDL_RenderCopy(renderer, galaxip_tex, NULL, &galaxip_rect);
        x += 20;
    }
}

void View::renderExplosions() {
    for(int i = 0; i < 60; i++) {
        if(model.getGreenAlien(i).getDyingAnimationCounter() > 0) {
            SDL_Rect explosion_rect = model.getGreenAlien(i).getRect();
            explosion_rect.w = 32;
            explosion_rect.h = 32;
            explosion_rect.x -= 8;
            explosion_rect.y -= 8;
            if(model.getGreenAlien(i).getDyingAnimationCounter() == 1) {
                SDL_RenderCopy(renderer, explosion1_tex, NULL, &explosion_rect);
            } else if(model.getGreenAlien(i).getDyingAnimationCounter() == 2) {
                SDL_RenderCopy(renderer, explosion2_tex, NULL, &explosion_rect);
            } else if(model.getGreenAlien(i).getDyingAnimationCounter() == 3) {
                SDL_RenderCopy(renderer, explosion3_tex, NULL, &explosion_rect);
            }
        }
        if(model.getBlueAlien(i).getDyingAnimationCounter() > 0) {
            SDL_Rect explosion_rect = model.getBlueAlien(i).getRect();
            explosion_rect.w = 32;
            explosion_rect.h = 32;
            explosion_rect.x -= 8;
            explosion_rect.y -= 8;
            if(model.getBlueAlien(i).getDyingAnimationCounter() == 1) {
                SDL_RenderCopy(renderer, explosion1_tex, NULL, &explosion_rect);
            } else if(model.getBlueAlien(i).getDyingAnimationCounter() == 2) {
                SDL_RenderCopy(renderer, explosion2_tex, NULL, &explosion_rect);
            } else if(model.getBlueAlien(i).getDyingAnimationCounter() == 3) {
                SDL_RenderCopy(renderer, explosion3_tex, NULL, &explosion_rect);
            }
        }
        if(model.getRedAlien(i).getDyingAnimationCounter() > 0) {
            SDL_Rect explosion_rect = model.getRedAlien(i).getRect();
            explosion_rect.w = 32;
            explosion_rect.h = 32;
            explosion_rect.x -= 8;
            explosion_rect.y -= 8;
            if(model.getRedAlien(i).getDyingAnimationCounter() == 1) {
                SDL_RenderCopy(renderer, explosion1_tex, NULL, &explosion_rect);
            } else if(model.getRedAlien(i).getDyingAnimationCounter() == 2) {
                SDL_RenderCopy(renderer, explosion2_tex, NULL, &explosion_rect);
            } else if(model.getRedAlien(i).getDyingAnimationCounter() == 3) {
                SDL_RenderCopy(renderer, explosion3_tex, NULL, &explosion_rect);
            }
        }
        if(model.getFlagship(i).getDyingAnimationCounter() > 0) {
            SDL_Rect explosion_rect = model.getFlagship(i).getRect();
            explosion_rect.w = 32;
            explosion_rect.h = 32;
            explosion_rect.x -= 8;
            explosion_rect.y -= 8;
            if(model.getFlagship(i).getDyingAnimationCounter() == 1) {
                SDL_RenderCopy(renderer, explosion1_tex, NULL, &explosion_rect);
            } else if(model.getFlagship(i).getDyingAnimationCounter() == 2) {
                SDL_RenderCopy(renderer, explosion2_tex, NULL, &explosion_rect);
            } else if(model.getFlagship(i).getDyingAnimationCounter() == 3) {
                SDL_RenderCopy(renderer, explosion3_tex, NULL, &explosion_rect);
            }
        }
    }
    if(model.getGalaxip().getDyingAnimationCounter() > 0) {
        SDL_Rect explosion_rect = model.getGalaxip().getRect();
        explosion_rect.w = 32;
        explosion_rect.h = 32;
        explosion_rect.x -= 8;
        explosion_rect.y -= 8;
        if(model.getGalaxip().getDyingAnimationCounter() == 1) {
            SDL_RenderCopy(renderer, explosion1_tex, NULL, &explosion_rect);
        } else if(model.getGalaxip().getDyingAnimationCounter() == 2) {
            SDL_RenderCopy(renderer, explosion2_tex, NULL, &explosion_rect);
        } else if(model.getGalaxip().getDyingAnimationCounter() == 3) {
            SDL_RenderCopy(renderer, explosion3_tex, NULL, &explosion_rect);
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

    num_0_sur = IMG_Load("images/0.png");
    num_0_tex = SDL_CreateTextureFromSurface(renderer, num_0_sur);
    SDL_FreeSurface(num_0_sur);

    num_1_sur = IMG_Load("images/1.png");
    num_1_tex = SDL_CreateTextureFromSurface(renderer, num_1_sur);
    SDL_FreeSurface(num_1_sur);

    num_2_sur = IMG_Load("images/2.png");
    num_2_tex = SDL_CreateTextureFromSurface(renderer, num_2_sur);
    SDL_FreeSurface(num_2_sur);

    num_3_sur = IMG_Load("images/3.png");
    num_3_tex = SDL_CreateTextureFromSurface(renderer, num_3_sur);
    SDL_FreeSurface(num_3_sur);

    num_4_sur = IMG_Load("images/4.png");
    num_4_tex = SDL_CreateTextureFromSurface(renderer, num_4_sur);
    SDL_FreeSurface(num_4_sur);

    num_5_sur = IMG_Load("images/5.png");
    num_5_tex = SDL_CreateTextureFromSurface(renderer, num_5_sur);
    SDL_FreeSurface(num_5_sur);

    num_6_sur = IMG_Load("images/6.png");
    num_6_tex = SDL_CreateTextureFromSurface(renderer, num_6_sur);
    SDL_FreeSurface(num_6_sur);

    num_7_sur = IMG_Load("images/7.png");
    num_7_tex = SDL_CreateTextureFromSurface(renderer, num_7_sur);
    SDL_FreeSurface(num_7_sur);

    num_8_sur = IMG_Load("images/8.png");
    num_8_tex = SDL_CreateTextureFromSurface(renderer, num_8_sur);
    SDL_FreeSurface(num_8_sur);

    num_9_sur = IMG_Load("images/9.png");
    num_9_tex = SDL_CreateTextureFromSurface(renderer, num_9_sur);
    SDL_FreeSurface(num_9_sur);

    explosion1_sur = IMG_Load("images/explosion1.png");
    explosion1_tex = SDL_CreateTextureFromSurface(renderer, explosion1_sur);
    SDL_FreeSurface(explosion1_sur);

    explosion2_sur = IMG_Load("images/explosion2.png");
    explosion2_tex = SDL_CreateTextureFromSurface(renderer, explosion2_sur);
    SDL_FreeSurface(explosion2_sur);

    explosion3_sur = IMG_Load("images/explosion3.png");
    explosion3_tex = SDL_CreateTextureFromSurface(renderer, explosion3_sur);
    SDL_FreeSurface(explosion3_sur);

    return 0;
}
