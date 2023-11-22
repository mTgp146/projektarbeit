#include "models/galaxip.h"
#include "models/projectile.h"
#include "models/green_alien.h"
#include <array>

class Model {
    public:
        void initAliens();
        Galaxip getGalaxip();
        Projectile getGalaxipProjectile();
        GreenAlien getGreenAlien(int index);
        void moveGalaxip(enum Galaxip::Direction direction);
        void shotByGalaxip();
        void gameActions();
        void resetGalaxipProjectile();
        bool intersects(SDL_Rect rect1, SDL_Rect rect2);
    private:
        Galaxip galaxip;
        std::array<GreenAlien, 30> greenAliens = {};
        Projectile projectileGalaxip{Projectile::TYPE::GALAXIP, galaxip.getRect().x+15, galaxip.getRect().y-8};
};