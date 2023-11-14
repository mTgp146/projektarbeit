#include "SDL2/SDL.h"

class Projectile  {
    public:
        enum TYPE { GALAXIP, ALIEN };
        Projectile(TYPE type, int x, int y);
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveProjectile(TYPE type);
        void setType(TYPE type);
        TYPE getType() const;

    private:
        SDL_Rect rect = SDL_Rect();
        TYPE type;

};
