#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Texture {

public:
    static SDL_Texture* loadTexture(const char *path, SDL_Renderer* renderer);

private:
    SDL_Texture *texture = nullptr;
}

#endif
