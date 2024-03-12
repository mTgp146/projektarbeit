#include "models/galaxip.h"
#include "models/alien.h"
#include "models/background.h"
#include "models/sounds.h"
#include "models/points.h"
#include "models/projectileGalaxip.h"
#include "models/projectileAlien.h"
#include <array>

/**
 * The Model class is responsible for the game logic and data.
*/
class Model {
    public:
        enum AlienTypes { G, B, R, F};
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
        ProjectileGalaxip getGalaxipProjectile();
        ProjectileAlien getAlienProjectile(int index);
        Alien getGreenAlien(int index);
        Alien getBlueAlien(int index);
        Alien getRedAlien(int index);
        Alien getFlagship(int index);
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
        /**
         * Moves the projectiles of the aliens in the game.
        */
        void moveAlienShots();
        /**
         * Checks if the attacking alien is moving to the middle.
         * @return true if the attacking alien is moving to the middle, false otherwise.
         */
        bool isAttackingAlienMovingToMiddle();
        /**
         * Get the Attacking Alien X object
         * @return the x position of the attacking alien
         */
        int getAttackingAlienX();
        /**
         * Get the Attacking Alien Y object
         * @return the y position of the attacking alien
         */
        int getAttackingAlienY();
        /**
         * move the attacking alien if the other aliens dont move
         */
        void moveAttackingAlien();
        /**
         * Try to revive the Galaxip if it is dead.
         */
        void tryToReviveGalaxip();
        /**
         * Check for explosions and increase the explosion counter.
         */
        void checkExplosions();
        /**
         * Check if a new attack should be started.
         */
        void checkForNewAttack();
        /**
         * Get the new attacker
         * @return the new attacker
         */
        int getNewAttacker();
        /**
         * Get the new attacking alien (type)
         * @param i the index of the attacking alien
         * @return the new attacking alien
         */
        int getNewAttackingAlien(int i);
        void setGameOver(bool gameOver);
        bool isGameOver();
        /**
         * Check if the game is over and start it new.
         */
        void checkGameOver();
        /**
         * Check if all aliens are dead and respawn them.
         */
        void checkIfAllAliensAreDead();

    private:
        int lastAlienDisplayChange = SDL_GetTicks();
        int alienFormationState = 0;
        Galaxip galaxip;
        std::array<Alien, 60> greenAliens = {};
        std::array<Alien, 60> blueAliens = {};
        std::array<Alien, 60> redAliens = {};
        std::array<Alien, 60> flagships = {};
        ProjectileGalaxip projectileGalaxip{galaxip.getRect().x+15, galaxip.getRect().y-8};
        std::array<ProjectileAlien, 2> projectilesAlien = {};
        Background background;
        Sounds sounds;
        Points points;
        bool alienInAttack = false;
        int attackingAlien = -1;
        AlienTypes attackingAlienType = G;
        int lastShot = SDL_GetTicks();
        int lastDeath = SDL_GetTicks();
        int lastAttack = SDL_GetTicks();
        bool gameOver = false;
};