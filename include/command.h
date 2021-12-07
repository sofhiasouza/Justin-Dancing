#ifndef COMMAND_H
#define COMMAND_H

#define WINDOW_WIDTH 840
#define WINDOW_HEIGHT 640

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "sprite.h"
#include <string>
#include <iostream>

class Texture;

enum state
{
    VALID,
    TARGET,
    INVALID,
    DESTROY
};

enum position
{
    POS_UP,
    POS_DOWN,
    POS_LEFT,
    POS_RIGHT
};

class Command: private Sprite{
private:
    int startTime;
    

public:
    position value;
    state actualState;

    Command(int value, const char* path);
    Command(int value, const char* path, const char* path2, const char* path3, const char* path4);

    static Command* generateCommand();
    void render();
    void update(pthread_mutex_t mutex);
    void target();
    void destroy();

};

#endif