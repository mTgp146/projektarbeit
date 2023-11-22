#include "view.h"
#include <iostream>

View::View(Model &model) : model(model) {}

void View::render() {
    SDL_RenderClear(renderer);

	renderGalaxip();
    renderGalaxipProjectile();
    renderGreenAliens();

	SDL_RenderPresent(renderer);
    tick_counter++;
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
    if(tick_counter == 30) {
        tick_counter = 0;
        if(green_alien_counter < 3) {
            green_alien_counter++;
        } else {
            green_alien_counter = 0;
        }
    }
    for (int i = 0; i < 30; i++) {
        if(model.getGreenAlien(i).isAlive()) {
            SDL_Rect green_alien_rect = model.getGreenAlien(i).getRect();
            int xPosGA = i%10;
            bool tex_1 = false;
            bool tex_2 = false;
            bool tex_3 = false;
            bool pos_even = xPosGA == 0 || xPosGA == 2 || xPosGA == 4 || xPosGA == 6 || xPosGA == 8;
            bool pos_odd  = xPosGA == 1 || xPosGA == 3 || xPosGA == 5 || xPosGA == 7 || xPosGA == 9;            
            bool pos_1_5_9= xPosGA == 1 || xPosGA == 5 || xPosGA == 9;
            bool pos_2_6  = xPosGA == 2 || xPosGA == 6;
            bool pos_3_7  = xPosGA == 3 || xPosGA == 7;
            bool pos_0_4_8= xPosGA == 0 || xPosGA == 4 || xPosGA == 8;
            /*
            2123212321
            3212321232
            2321232123
            1232123212
            */
            if(green_alien_counter == 0 || green_alien_counter == 2) {
                tex_2 = pos_even;
                if(green_alien_counter == 0) {
                    tex_1 = pos_1_5_9;
                    tex_3 = pos_3_7;
                } else {
                    tex_1 = pos_3_7;
                    tex_3 = pos_1_5_9;
                }
            } else {
                tex_2 = pos_odd;
                if(green_alien_counter == 1) {
                    tex_1 = pos_2_6;
                    tex_3 = pos_0_4_8;
                } else {
                    tex_1 = pos_0_4_8;
                    tex_3 = pos_2_6;
                }
            }

            if(tex_1) {
                SDL_RenderCopy(renderer, green_alien1_tex, NULL, &green_alien_rect);
            } else if(tex_2) {
                SDL_RenderCopy(renderer, green_alien2_tex, NULL, &green_alien_rect);
            } else {
                SDL_RenderCopy(renderer, green_alien3_tex, NULL, &green_alien_rect);
            }
        }
    }
}

void View::exit() {
    SDL_DestroyTexture(galaxip_tex);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
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

    return 0;

}
