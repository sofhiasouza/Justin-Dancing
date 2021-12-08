#include "../include/players.h"


Players::Players(){

    pointsP1 = 0;
    pointsP2 = 0;

}

Players::~Players(){

}

int Players::tryMatch(int movement, Command** actualCommand){

    switch((*actualCommand)->value)
    {
        case POS_UP:
            if(movement == SDL_SCANCODE_UP)
            {
                pointsP2++;  
                (*actualCommand)->flagPointP2 = 1;
                (*actualCommand)->actualState = INVALID;
            }
            else if(movement == SDL_SCANCODE_DOWN || movement == SDL_SCANCODE_LEFT || movement == SDL_SCANCODE_RIGHT)
            {
                if((*actualCommand)->flagFailureP2 == 0) failuresP2++;
                (*actualCommand)->flagFailureP2 = 1;
            }

            if(movement == SDL_SCANCODE_W)
            {
                pointsP1++;
                (*actualCommand)->flagPointP1 = 1;
                (*actualCommand)->actualState = INVALID;
                
            }
            else if(movement == SDL_SCANCODE_A || movement == SDL_SCANCODE_S || movement == SDL_SCANCODE_D)
            {
                if((*actualCommand)->flagFailureP1 == 0) failuresP1++;
                (*actualCommand)->flagFailureP1 = 1;
            }
            
            
            break;

        case POS_DOWN:
            if(movement == SDL_SCANCODE_DOWN)
            {
                pointsP2++;  
                (*actualCommand)->flagPointP2 = 1;
                (*actualCommand)->actualState = INVALID;
            }
            else if(movement == SDL_SCANCODE_UP || movement == SDL_SCANCODE_LEFT || movement == SDL_SCANCODE_RIGHT)
            {
                if((*actualCommand)->flagFailureP2 == 0) failuresP2++;
                (*actualCommand)->flagFailureP2 = 1;
            }

            if(movement == SDL_SCANCODE_S)
            {
                pointsP1++;
                (*actualCommand)->flagPointP1 = 1;
                (*actualCommand)->actualState = INVALID;
                
            }
            else if(movement == SDL_SCANCODE_A || movement == SDL_SCANCODE_D || movement == SDL_SCANCODE_W)
            {
                if((*actualCommand)->flagFailureP1 == 0) failuresP1++;
                (*actualCommand)->flagFailureP1 = 1;
            }
            
            
            break;

        case POS_LEFT:
         if(movement == SDL_SCANCODE_LEFT)
            {
                pointsP2++;  
                (*actualCommand)->flagPointP2 = 1;
                (*actualCommand)->actualState = INVALID;
            }
            else if(movement == SDL_SCANCODE_DOWN || movement == SDL_SCANCODE_UP || movement == SDL_SCANCODE_RIGHT)
            {
                if((*actualCommand)->flagFailureP2 == 0) failuresP2++;
                (*actualCommand)->flagFailureP2 = 1;
            }

            if(movement == SDL_SCANCODE_A)
            {
                pointsP1++;
                (*actualCommand)->flagPointP1 = 1;
                (*actualCommand)->actualState = INVALID;
                
            }
            else if(movement == SDL_SCANCODE_W || movement == SDL_SCANCODE_S || movement == SDL_SCANCODE_D)
            {
                if((*actualCommand)->flagFailureP1 == 0) failuresP1++;
                (*actualCommand)->flagFailureP1 = 1;
            }
            
           
            break;

        case POS_RIGHT:
            if(movement == SDL_SCANCODE_RIGHT)
            {
                pointsP2++;  
                (*actualCommand)->flagPointP2 = 1;
                (*actualCommand)->actualState = INVALID;
            }
            else if(movement == SDL_SCANCODE_DOWN || movement == SDL_SCANCODE_LEFT || movement == SDL_SCANCODE_UP)
            {
                if((*actualCommand)->flagFailureP2 == 0) failuresP2++;
                (*actualCommand)->flagFailureP2 = 1;
            }

            if(movement == SDL_SCANCODE_D)
            {
                pointsP1++;
                (*actualCommand)->flagPointP1 = 1;
                (*actualCommand)->actualState = INVALID;
                
            }
            else if(movement == SDL_SCANCODE_A || movement == SDL_SCANCODE_S || movement == SDL_SCANCODE_W)
            {
                if((*actualCommand)->flagFailureP1 == 0) failuresP1++;
                (*actualCommand)->flagFailureP1 = 1;
            }
            
            
            break;
    }
    
    return 0;
}


