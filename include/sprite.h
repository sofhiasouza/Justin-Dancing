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
   
    SDL_Texture *textureJ1, *textureJ2, *textureBG;


public:
    SDL_Texture *textureCommands;
    Sprite();
    Sprite(const char* path);
    Sprite(const char *path2, const char *path3, const char *path4);

    void changeImage(const char* pathCommands);
    void render();
    void renderEnvironment();
    bool update();

    void setX(int x);
    void setY(int y);
    void setPos(int x, int y);


};

#endif
