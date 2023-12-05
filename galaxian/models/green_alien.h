#include "SDL2/SDL.h"

class GreenAlien {
    public:
        enum Direction { LEFT, RIGHT };
        GreenAlien();
        void setPositionInFormation(int position);
        SDL_Rect getRect() const;
        void setX(int x);
        void setY(int y);
        void moveGreenAlienAlongXAxis();
        bool isAlive() const;
        void setAlive(bool alive);
        void changeDirection();
        void setLastUpdate();
        Direction getDirection() const;
        int getTextureNumber();
        void setTextureNumber(int texNum);
    private:
        float realX = 0.0f;
        int lastUpdate;
        int textureNumber = 1;
        SDL_Rect rect = SDL_Rect();
        bool alive = true;
        Direction direction = LEFT;
};
