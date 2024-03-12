#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "SDL2/SDL.h"

/**
 * The Projectile class represents a projectile in the game.
*/
class Projectile  {
    public:
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        bool isAlive() const;
        void setAlive(bool alive);
        /**
         * Sets the last update time to the current time.
        */
        void setLastUpdate();

    protected:
        int lastUpdate;
        SDL_Rect rect = SDL_Rect();
        bool alive = false;
        float realY = 0.0f;

};

#endif // PROJECTILE_H	