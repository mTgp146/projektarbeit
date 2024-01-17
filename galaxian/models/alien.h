#ifndef ALIEN_H
#define ALIEN_H

#include "SDL2/SDL.h"

class Alien {
    public:
        enum Direction { LEFT, RIGHT };
        Alien();
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveAlien();
        void moveAttackingAlien();
        void moveAlienAlongXAxis();
        bool isAlive() const;
        void setAlive(bool alive);
        void changeDirection();
        void setLastUpdate();
        Direction getDirection() const;
        int getTextureNumber();
        void setTextureNumber(int texNum);
        void setAttackMode(bool attackMode);
        bool isInAttackMode() const;
    protected:
        float realX = 0.0f;
        float realY = 0.0f;
        int lastUpdate;
        int textureNumber = 1;
        SDL_Rect rect = SDL_Rect();
        bool alive = true;
        Direction direction = LEFT;
        bool attackMode = false;
};

#endif // ALIEN_H