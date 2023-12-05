#include "models/galaxip.h"
#include "models/projectile.h"
#include "models/green_alien.h"
#include <array>

class Model {
    public:
        void initAliens();
        Galaxip getGalaxip();
        void setGalaxipDT();
        Projectile getGalaxipProjectile();
        GreenAlien getGreenAlien(int index);
        void moveGalaxip(enum Galaxip::Direction direction);
        void shotByGalaxip();
        void gameActions();
        void resetGalaxipProjectile();
        bool intersects(SDL_Rect rect1, SDL_Rect rect2);
        bool changeAlienDisplay();
        void moveGalaxipProjectile();
        void moveAliens();
        void alienDisplayChanger();
        void collisionCheck();
    private:
        int lastAlienDisplayChange = SDL_GetTicks();
        int alienFormationState = 0;
        Galaxip galaxip;
        std::array<GreenAlien, 30> greenAliens = {};
        Projectile projectileGalaxip{Projectile::TYPE::GALAXIP, galaxip.getRect().x+15, galaxip.getRect().y-8};
};