#ifndef COMMAND_H
#define COMMAND_H

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "sprite.h"
#include <string>

class Texture;

enum state
{
    VALID,
    PAYER1,
    PLAYER2,
    INVALID,
    DESTROY
};

class Command: private Sprite{
private:
    int startTime;
    int value;

public:
    state actualState;

    Command(int value, const char* path);

    static Command* generateCommand();
    void render();
    void update();
    void destroy();

};

#endif