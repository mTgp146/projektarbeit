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
        void moveAlien();
        /**
         * Moves the alien in the game when it is attacking.
        */
        void moveAttackingAlien();
        /**
         * Moves the alien in the game when it is not attacking.
        */
        void moveAlienAlongXAxis();
        bool isAlive() const;
        void setAlive(bool alive);
        void changeDirection();
        /**
         * Sets the last update time to the current time.
        */
        void setLastUpdate();
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
    protected:
        float realX = 0.0f;
        float realY = 0.0f;
        int lastUpdate;
        int textureNumber = 1;
        SDL_Rect rect = SDL_Rect();
        bool alive = true;
        bool inGame = false;
        Direction direction = LEFT;
        bool attackMode = false;
};

#endif // ALIEN_H