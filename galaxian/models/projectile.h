#include "SDL2/SDL.h"

/**
 * The Projectile class represents a projectile in the game.
*/
class Projectile  {
    public:
        /**
         * The type of the projectile.
        */
        enum TYPE { GALAXIP, ALIEN };
        /**
         * The constructor of the Projectile class.
         * @param type The type of the projectile.
         * @param x The x coordinate of the projectile.
         * @param y The y coordinate of the projectile.
        */
        Projectile(TYPE type, int x, int y);
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        /**
         * Moves the projectile in the game by a defined amount.
        */
        void moveProjectile();
        TYPE getType() const;
        bool isAlive() const;
        void setAlive(bool alive);
        /**
         * Sets the last update time to the current time.
        */
        void setLastUpdate();

    private:
        int lastUpdate;
        SDL_Rect rect = SDL_Rect();
        TYPE type;
        bool alive = false;
        float realY = 0.0f;

};
