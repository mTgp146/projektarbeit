#include "projectile.h" 

class ProjectileAlien : public Projectile {
    public:
        enum Types { G, B, R, F};
        /**
         * The constructor of the ProjectileAlien class.
         * @param x The x coordinate of the projectile.
         * @param y The y coordinate of the projectile.
         */
        ProjectileAlien();
        /**
         * Moves the projectile in the game by a defined amount.
         */
        void shoot(int x, int y, int galaxipPosX, Types type);
        void moveProjectile();
    private:
        float realX = 0.0f;
        float galaxyPosX = 0.0f;
        float initialX = 0.0f;
        float initialY = 0.0f;
        float heightOfGalaxip = 448.0f;
        Types type;
};