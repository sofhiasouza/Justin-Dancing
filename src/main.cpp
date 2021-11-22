#include "../include/game.h"
#include <iostream>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

const int FPS = 60;
const int frameDelay = 1000/FPS;


Game *game = nullptr;

int main() {

    game = new Game();

    game->init("Justin Dancing", WINDOW_WIDTH, WINDOW_HEIGHT);

    while(game->isRunning()) {

        //Tempo desde a inicializacao do SDL
        frameStart = SDL_GetTicks();

        game->handleEvent();
        game->update();
        game->render();

        //Duração do frame
        frameTime = SDL_GetTicks() - frameStart;
    
        //Gera um delay para que o tempo entre os frames não seja tão curto
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}