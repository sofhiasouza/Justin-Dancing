#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

class Texture {

public:
    static SDL_Texture* loadTexture(const char *path);
    static void renderCommands(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
    static void renderJustins(SDL_Texture *tex, SDL_Texture *tex2);
    static void renderBG(SDL_Texture *tex);
};

#endif
