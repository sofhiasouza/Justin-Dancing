#include "../include/game.h"
#include <iostream>
#include <string>

const int FPS = 240;
const int frameDelay = 1000/FPS;
const Uint8 *keyboardStateArray = SDL_GetKeyboardState(NULL);

Uint32 frameStart;
int frameCounter;
int frameTime;
Game *game = nullptr;

pthread_t buttonThread[8];
int buttonTypes[8] = {82, 81, 80, 79, 26, 22, 4, 7};

// Essa função é chamada para processar cada checador em threads distintas
void *buttonCheckThread(void *arg){

    int *movement = (int *) arg;

    // Looping de atualização
    while(game->isRunning()){
        unsigned int threadFrameStart = SDL_GetTicks();

        //verifica se a tecla correspondente do checador está pressionada
        if(keyboardStateArray[*movement]) {

            // Entrando na região critica
            pthread_mutex_lock(&game->mutex);

            game->tryMatchCommand(*movement);  

            // Saindo da região crítica
            pthread_mutex_unlock(&game->mutex);
       }
       else
       {
        
       }

        //Duração do frame
        unsigned int threadFrameTime = SDL_GetTicks() - threadFrameStart;
    
        ////Gera um delay para que o tempo entre os frames não seja tão curto
        if(frameDelay > threadFrameTime){
            SDL_Delay(frameDelay - threadFrameTime);
        }
    }

    pthread_exit(NULL);
}


void createButtonThreads(){
     // Criando atributo para definir as threads como JOINABLE
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Criando threads
    for(int i = 0;i < 8;i++){
        pthread_create(&buttonThread[i], &attr, buttonCheckThread, (void*)&(buttonTypes[i]));
    }

    // Destruindo atributo
    pthread_attr_destroy(&attr);
}

// Aguarda a finalização de todas as threads
void joinButtonThreads(){
    for(int i = 0;i < 8;i++){
        pthread_join(buttonThread[i], NULL);
    }
}

int main(){

    // Setando semente para a geração de número aleatórios
    srand(time(NULL));

    game = new Game();

    // Criando threads dos checadores
    createButtonThreads();

    game->init("Justin Dancing", WINDOW_WIDTH, WINDOW_HEIGHT);

    while(game->isRunning()) {

        //Tempo desde a inicializacao do SDL
        frameStart = SDL_GetTicks();
        frameCounter++;
        frameCounter %= 6000; // zera a cada 100 segundos

        game->handleEvent();
        game->update(frameCounter);
        game->render();

        //Duração do frame
        frameTime = SDL_GetTicks() - frameStart;
    
        ////Gera um delay para que o tempo entre os frames não seja tão curto
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    // Esperando a finalização das threads
    joinButtonThreads();

    game->clean();

    return 0;
}