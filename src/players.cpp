#include "../include/players.h"


Players::Players(){

    pointsP1 = 0;
    pointsP2 = 0;

}

Players::~Players(){

}

void Players::tryMatchP1(int movement, Command* actualCommand){

    switch(actualCommand->value)
    {
        case POS_UP:
            if(movement == SDL_SCANCODE_W)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_DOWN:
            if(movement == SDL_SCANCODE_S)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_LEFT:
            if(movement == SDL_SCANCODE_A)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_RIGHT:
            if(movement == SDL_SCANCODE_D)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
            }
            break;
    }

}

void Players::tryMatchP2(int movement, Command* actualCommand){

    switch(actualCommand->value)
    {
        case POS_UP:
            if(movement == SDL_SCANCODE_UP)
            {
                pointsP2++;  
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_DOWN:
            if(movement == SDL_SCANCODE_DOWN)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_LEFT:
            if(movement == SDL_SCANCODE_LEFT)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
            }
            break;

        case POS_RIGHT:
            if(movement == SDL_SCANCODE_RIGHT)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
            }
            break;
    }
}

