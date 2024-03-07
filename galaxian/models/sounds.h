#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Sounds {
    public:
        Sounds();
        ~Sounds();
        void playShot();
        void playExplosion();
        void playBackground();
        void stopBackground();
    private:
        Mix_Chunk *shot = NULL;
        Mix_Chunk *explosion = NULL;
        Mix_Music *background = NULL;
};