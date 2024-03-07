#include "models/galaxip.h"
#include "models/projectile.h"
#include "models/green_alien.h"
#include "models/blue_alien.h"
#include "models/red_alien.h"
#include "models/flagship.h"
#include "models/background.h"
#include <array>
#include <vector>
#include <variant>

class Model {
    public:
        void initAliens();
        Galaxip getGalaxip();
        void setGalaxipDT();
        Projectile getGalaxipProjectile();
        GreenAlien getGreenAlien(int index);
        BlueAlien getBlueAlien(int index);
        RedAlien getRedAlien(int index);
        Flagship getFlagship(int index);
        Alien::Type getAlienType(int index);
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
        void updateBackground();
        std::array<BackgroundParticle, 128> getBackgroundParticles();

    private:
        int lastAlienDisplayChange = SDL_GetTicks();
        int alienFormationState = 0;
        Galaxip galaxip;
        //std::array<GreenAlien, 30> greenAliens = {};
        //std::array<BlueAlien, 8> blueAliens = {};
        //std::array<RedAlien, 6> redAliens = {};
        //std::array<Flagship, 10> flagships = {};
        //std::array<Alien, 60> aliens = {};
        std::vector<std::variant<GreenAlien, BlueAlien, RedAlien, Flagship>> aliens = {};
        Projectile projectileGalaxip{Projectile::TYPE::GALAXIP, galaxip.getRect().x+15, galaxip.getRect().y-8};
        Background background;
        ///
        //bool attack = false;
        ///
};