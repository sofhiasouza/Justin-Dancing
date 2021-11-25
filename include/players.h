#ifndef PLAYERS_H
#define PLAYERS_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include "command.h"

using namespace std;

enum keys
{
    NONE,
    W,
    A,
    S,
    D,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Players {

private:
    


public:
    Players();
    ~Players();
    int pointsP1;
    int pointsP2;
    keys keyInputP1(SDL_Event event);
    keys keyInputP2(SDL_Event event);
    void tryMatchP1(SDL_Event event, Command* actualCommand);
    void tryMatchP2(SDL_Event event, Command* actualCommand);


};

#endif