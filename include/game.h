#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>

class Game {

private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int windowWidth = -1;
    int windowHeight = -1;
    bool run = true;

public:
    Game();
    ~Game();

    void init(const char* title, int width, int height);

    void handleEvent();
    void update();
    void render();
    void clean();
    bool isRunning();
};

#endif