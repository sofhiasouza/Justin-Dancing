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