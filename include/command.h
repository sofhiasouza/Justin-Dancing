#ifndef COMMAND_H
#define COMMAND_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "texture.h"
#include "sprite.h"
#include <string>


class Command: private Sprite{
private:
    int startTime;
    int value;

public:
    Command(int value, const char* path);

    void render();
    void update();

};

#endif
