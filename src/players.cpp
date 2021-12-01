#include "../include/players.h"


Players::Players(){

    pointsP1 = 0;
    pointsP2 = 0;

}

Players::~Players(){

}

keys Players::keyInputP1(int movement){


    switch(movement)
    {
        case SDL_SCANCODE_W:
            return W;
            break;

        case SDL_SCANCODE_A:
            return A;
            break;

        case SDL_SCANCODE_S:
            return S;
            break;

        case SDL_SCANCODE_D:
            return D;
            break;
    }

    return NONE;
}

keys Players::keyInputP2(int movement){


    switch(movement)
    {
        case SDL_SCANCODE_UP:
            return UP;
            break;

        case SDL_SCANCODE_DOWN:
            return DOWN;
            break;

        case SDL_SCANCODE_LEFT:
            return LEFT;
            break;

        case SDL_SCANCODE_RIGHT:
            return RIGHT;
            break;  
    }


    return NONE;
}

void Players::tryMatchP1(int movement, Command* actualCommand){

    keys keyPressedP1 = keyInputP1(movement);

    switch(actualCommand->value)
    {
        case POS_UP:
            if(keyPressedP1 == W)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;

        case POS_DOWN:
            if(keyPressedP1 == S)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;

        case POS_LEFT:
            if(keyPressedP1 == A)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;

        case POS_RIGHT:
            if(keyPressedP1 == D)
            {
                pointsP1++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;
    }

}

void Players::tryMatchP2(int movement, Command* actualCommand){

   keys keyPressedP2 = keyInputP2(movement);

    switch(actualCommand->value)
    {
        case POS_UP:
            if(keyPressedP2 == UP)
            {
                pointsP2++;  
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            } 
            break;

        case POS_DOWN:
            if(keyPressedP2 == DOWN)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;

        case POS_LEFT:
            if(keyPressedP2 == LEFT)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;

        case POS_RIGHT:
            if(keyPressedP2 == RIGHT)
            {
                pointsP2++;
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
            }
            break;
    }
}

