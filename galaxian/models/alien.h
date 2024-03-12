#ifndef ALIEN_H
#define ALIEN_H

#include "SDL2/SDL.h"

/**
 * The Alien class represents an alien in the game.
*/
class Alien {
    public:
        /**
         * The Direction enum represents the direction in which the alien is moving.
        */
        enum Direction { LEFT, RIGHT };
        Alien();
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveAlien(int galaxipPos, Direction dir);
        /**
         * Moves the alien in the game when it is attacking.
        */
        void moveAttackingAlien(int galaxipPos, bool callFromModel, Direction dir);
        /**
         * Moves the alien in the game when it is not attacking.
        */
        void moveAlienAlongXAxis(int dt);
        bool isAlive() const;
        void setAlive(bool alive);
        void changeDirection();
        /**
         * Sets the last update time to the current time.
        */
        void setLastUpdate();
        void setLastAttackUpdate();
        Direction getDirection() const;
        int getTextureNumber();
        void setTextureNumber(int texNum);
        void setAttackMode(bool attackMode);
        bool isInAttackMode() const;
        void setInGame(bool inGame);
        bool isInGame() const;
        /**
         * Sets the position of the alien in the formation.
         * @param position The index of the alien in the formation.
        */
        void setPositionInFormation(int position);
        void moveInCircle(int dt, Direction dir);
        void moveToMiddle(int dt, Direction dir);
        void moveAlienToGalaxip(int dt);
        bool isIsMovingToMiddle() const;
        int getDyingAnimationCounter() const;
        void increaseDyingAnimationCounter();
        void setDyingAnimationCounter(int dyingAnimationCounter);
        int getDyingAnimationLast() const;
        void setDyingAnimationLast();
        void setReturnMode(bool returnMode);
        bool isReturnMode() const;

    protected:
        float middleOfScreen = 245.0f;
        float heightOfGalaxip = 448.0f;
        float realX = 0.0f;
        float realY = 0.0f;
        float attackX = 0.0f;
        float attackY = 0.0f;
        float attackStartX = 0.0f;
        float attackStartY = 0.0f;
        int lastUpdate;
        int lastAttackUpdate;
        int textureNumber = 1;
        SDL_Rect rect = SDL_Rect();
        bool alive = true;
        bool inGame = false;
        Direction direction = LEFT;
        bool attackMode = false;
        bool returnMode = false;
        float moveToGalaxipStartX = 0.0f;
        int galaxipPositionAtStartOfAttack = 0;
        bool isMovingToGalaxip = false;
        bool isMovingToMiddle = false;
        int dyingAnimationCounter = 0;
        int dyingAnimationLast = SDL_GetTicks();
        float initialY = 0.0f;
};

#endif // ALIEN_H