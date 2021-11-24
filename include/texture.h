#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Texture {

public:
    static SDL_Texture* loadTexture(const char *path);
    static void render(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

};

#endif
