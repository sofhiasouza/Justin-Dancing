#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "texture.h"

class Command;

class Sprite{

friend class Command;

private:
    int x;
    int y;
    SDL_Rect srcRect, destRect;
    SDL_Texture *texture;

public:
    Sprite();
    Sprite(const char* path);

    void render();
    bool update();

    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);


};

#endif
