#include "SDL2/SDL.h"

class GreenAlien {
    public:
        GreenAlien();
        void setPositionInFormation(int position);
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveGreenAlien();
        bool isAlive() const;
        void setAlive(bool alive);
    private:
        SDL_Rect rect = SDL_Rect();
        bool alive = true;
};
