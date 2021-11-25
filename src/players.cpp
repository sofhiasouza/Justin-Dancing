#include "../include/players.h"


Players::Players(){

    pointsP1 = 0;
    pointsP2 = 0;

}

Players::~Players(){

}

keys Players::keyInputP1(SDL_Event event){

    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_w:
                return W;
                break;

            case SDLK_a:
                return A;
                break;

            case SDLK_s:
                return S;
                break;

            case SDLK_d:
                return D;
                break;
        }
    }
    return NONE;
}

keys Players::keyInputP2(SDL_Event event){

    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                return UP;
                break;

            case SDLK_DOWN:
                return DOWN;
                break;

            case SDLK_LEFT:
                return LEFT;
                break;

            case SDLK_RIGHT:
                return RIGHT;
                break;  
        }
    }

    return NONE;
}

void Players::tryMatchP1(SDL_Event event, Command* actualCommand){

    keys keyPressedP1 = keyInputP1(event);

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

void Players::tryMatchP2(SDL_Event event, Command* actualCommand){

   keys keyPressedP2 = keyInputP2(event);

    switch(actualCommand->value)
    {
        case POS_UP:
            if(keyPressedP2 == UP)
            {
                actualCommand->actualState = INVALID;
                cout<<pointsP1 << " " << pointsP2 << endl;
                pointsP2++;  
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

