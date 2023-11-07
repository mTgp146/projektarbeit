#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*
mingw32-make
cmake -G "MinGW Makefiles" .
*/


const int WIDTH = 448, HEIGHT = 512;
double m_galaxip_x = 208.0, m_galaxip_y = 284.0;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    if (IMG_Init(IMG_INIT_PNG) == 0) {
	    std::cout << "Error SDL2_image Initialization";
	    return 2;
    }

    SDL_Window *window = SDL_CreateWindow( "Galaxian", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window ) {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
	    std::cout << "Error renderer creation";
	    return 4;
    }

    SDL_Surface* galaxip_sur = IMG_Load("images/Galaxip.png");
    if (galaxip_sur == NULL) {
	    std::cout << "Error loading image: " << IMG_GetError();
	    return 5;
    }

    SDL_Texture* galaxip_tex = SDL_CreateTextureFromSurface(renderer, galaxip_sur);
    if (galaxip_tex == NULL) {
	    std::cout << "Error creating texture";
	    return 6;
    }

    SDL_Rect galaxip_rect = SDL_Rect();
    galaxip_rect.x = m_galaxip_x;
    galaxip_rect.y = m_galaxip_y;
    galaxip_rect.w = 32;
    galaxip_rect.h = 32;


    SDL_FreeSurface(galaxip_sur);



    SDL_Event windowEvent;

    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type ) { 
                break; 
                }
        }
        
        m_galaxip_x = m_galaxip_x + 1*(1.0/60.0);
        galaxip_rect.x = m_galaxip_x;

        SDL_RenderClear(renderer);
	    SDL_RenderCopy(renderer, galaxip_tex, NULL, &galaxip_rect);
	    SDL_RenderPresent(renderer);

    }

	SDL_DestroyTexture(galaxip_tex);
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}