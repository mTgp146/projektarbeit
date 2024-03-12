#include "projectile.h"

class ProjectileGalaxip : public Projectile {
    public:
        /**
         * The constructor of the ProjectileGalaxip class.
         * @param x The x coordinate of the projectile.
         * @param y The y coordinate of the projectile.
         */
        ProjectileGalaxip(int x, int y);
        /**
         * Moves the projectile in the game by a defined amount.
         */
        void moveProjectile();
    private:
};