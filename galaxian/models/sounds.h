#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/**
 * The Sounds class is responsible for playing the sounds of the game.
*/
class Sounds {
    public:
        Sounds();
        ~Sounds();
        /**
         * Play the sound of a shot one time.
        */
        void playShot();
        /**
         * Play the sound of an explosion one time.
        */
        void playExplosion();
        /**
         * Start the background music loop.
        */
        void playBackground();
        /**
         * Stop the background music loop.
        */
        void stopBackground();
    private:
        Mix_Chunk *shot = NULL;
        Mix_Chunk *explosion = NULL;
        Mix_Music *background = NULL;
};