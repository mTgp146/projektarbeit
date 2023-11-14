#include "models/galaxip.h"
#include "models/projectile.h"

class Model {
    public:
        Galaxip getGalaxip();
        Projectile getGalaxipProjectile();
        void moveGalaxip(enum Galaxip::Direction direction);
        void shotByGalaxip();
        void gameActions();
    private:
        Galaxip galaxip;
        Projectile projectileGalaxip{Projectile::TYPE::GALAXIP, galaxip.getRect().x+15, galaxip.getRect().y-8};
};