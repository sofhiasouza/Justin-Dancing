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
    int failuresP1;
    int failuresP2;
    keys keyInputP1(int movement);
    keys keyInputP2(int movement);
    int tryMatch(int movement, Command** actualCommand);



};

#endif