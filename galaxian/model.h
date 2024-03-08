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

/**
 * The Model class is responsible for the game logic and data.
*/
class Model {
    public:
        /**
         * Initializes the aliens.
         * It sets their positions in the formation.
         * The positions are read from a file.
        */
        void initAliens();
        Galaxip getGalaxip();
        /**
         * Sets the lastUpdate variable of the Galaxip object to the current time.
        */
        void setGalaxipDT();
        Projectile getGalaxipProjectile();
        GreenAlien getGreenAlien(int index);
        BlueAlien getBlueAlien(int index);
        RedAlien getRedAlien(int index);
        Flagship getFlagship(int index);
        /**
         * Moves the Galaxip in the game.
         * @param direction The direction in which the Galaxip is moving.
        */
        void moveGalaxip(enum Galaxip::Direction direction);
        /**
         * Shoots a projectile from the Galaxip if there is no current projectile on the screen.
        */
        void shotByGalaxip();
        /**
         * Updates the game state.
         * It calls the different game actions.
        */
        void gameActions();
        /**
         * Resets the projectile of the Galaxip to its initial position.
        */
        void resetGalaxipProjectile();
        /**
         * Checks if two rectangles intersect.
         * @param rect1 The first rectangle.
         * @param rect2 The second rectangle.
         * @return True if the rectangles intersect, false otherwise.
        */
        bool intersects(SDL_Rect rect1, SDL_Rect rect2);
        /**
         * Checks if the display of the aliens should be changed.
         * The display is changed every 400ms.
         * @return True if the display should change, false otherwise.
        */
        bool changeAlienDisplay();
        /**
         * Moves the projectile of the Galaxip in the game.
        */
        void moveGalaxipProjectile();
        /**
         * Moves the aliens in the game.
        */
        void moveAliens();
        /**
         * Changes the display of the aliens if changeAlienDisplay() returns true.
         * The display is changed to simulate the movement of the aliens.
        */
        void alienDisplayChanger();
        /**
         * checks if the projectile of the Galaxip collides with an alien.
        */
        void collisionCheck();
        /**
         * Updates the background of the game.
        */
        void updateBackground();
        std::array<BackgroundParticle, 128> getBackgroundParticles();
        /**
         * Plays the music of the game.
        */
        void startMusic();
        /**
         * Adds points to the player's score.
         * @param value The value of the alien that was destroyed.
        */
        void addPoints(Points::Values value);
        int getPoints();
        /**
         * Resets the points of the player to 0.
        */
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