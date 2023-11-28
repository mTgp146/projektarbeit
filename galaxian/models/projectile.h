#include "SDL2/SDL.h"

class Projectile  {
    public:
        enum TYPE { GALAXIP, ALIEN };
        Projectile(TYPE type, int x, int y);
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveProjectile();
        TYPE getType() const;
        bool isAlive() const;
        void setAlive(bool alive);
        void setLastUpdate();

    private:
        int lastUpdate;
        SDL_Rect rect = SDL_Rect();
        TYPE type;
        bool alive = false;
        float realY = 0.0f;

};
