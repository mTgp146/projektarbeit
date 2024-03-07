#include "models/galaxip.h"
#include "models/projectile.h"
#include "models/green_alien.h"
#include "models/blue_alien.h"
#include "models/red_alien.h"
#include "models/flagship.h"
#include "models/background.h"
#include "models/sounds.h"
#include "models/points.h"
#include <array>

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
        void startMusic();
        void addPoints(Points::Values value);
        int getPoints();
        void resetPoints();
    private:
        int lastAlienDisplayChange = SDL_GetTicks();
        int alienFormationState = 0;
        Galaxip galaxip;
        std::array<GreenAlien, 60> greenAliens = {};
        std::array<BlueAlien, 60> blueAliens = {};
        std::array<RedAlien, 60> redAliens = {};
        std::array<Flagship, 60> flagships = {};
        Projectile projectileGalaxip{Projectile::TYPE::GALAXIP, galaxip.getRect().x+15, galaxip.getRect().y-8};
        Background background;
        Sounds sounds;
        Points points;
};