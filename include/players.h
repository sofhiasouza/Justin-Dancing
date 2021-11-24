#ifndef PLAYERS_H
#define PLAYERS_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>


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
    int pointsP1;
    int pointsP2;


public:
    Players();
    ~Players();

    keys keyInputP1(SDL_Event event);
    keys keyInputP2(SDL_Event event);
};

#endif