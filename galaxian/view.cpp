#include "view.h"
#include <iostream>

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
    if (galaxip_sur == NULL) {
	    std::cout << "Error loading image: " << IMG_GetError();
	    return 5;
    }

    galaxip_tex = SDL_CreateTextureFromSurface(renderer, galaxip_sur);
    if (galaxip_tex == NULL) {
	    std::cout << "Error creating texture";
	    return 6;
    }

    galaxip_rect.x = m_galaxip_x;
    galaxip_rect.y = m_galaxip_y;
    galaxip_rect.w = 32;
    galaxip_rect.h = 32;


    SDL_FreeSurface(galaxip_sur);
    return 0;

}

void View::render() {
    m_galaxip_x = m_galaxip_x + 1*(1.0/60.0);
    galaxip_rect.x = m_galaxip_x;

    SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, galaxip_tex, NULL, &galaxip_rect);
	SDL_RenderPresent(renderer);
}

void View::exit() {
    SDL_DestroyTexture(galaxip_tex);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit();
}