#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include "command.h"
#include "players.h"

using namespace std;

class Game {

private:
    SDL_Window *window = nullptr;
    int windowWidth = -1;
    int windowHeight = -1;
    bool run = true;

    
    list<Command*>::iterator commandsIterator;    
    list<Command*>::iterator targetCommandIterator;

    Players* players;

public:
    list<Command*> commands; 

    Game();
    ~Game();

    void init(const char* title, int width, int height);

    void handleEvent();
    void update(int frameCounter);
    void render();
    void clean();
    bool isRunning();

    static SDL_Renderer *renderer;
    static SDL_Event event;
};

#endif