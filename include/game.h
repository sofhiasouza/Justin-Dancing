#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include "players.h"
#include <pthread.h>

using namespace std;

class Game {

private:
    SDL_Window *window = nullptr;
    int windowWidth = -1;
    int windowHeight = -1;
    bool run = true;
    int flagPointJ1, flagPointJ2;

    
    list<Command*>::iterator commandsIterator;    
    list<Command*>::iterator targetCommandIterator;

    TTF_Font *font;
    SDL_Texture* t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8, *t9, *t10;

public:
    Sprite* environment;
    list<Command*> commands; 
    bool GameOver;
    // Mutex de acesso à variável actualState dos comandos
    pthread_mutex_t mutex;

    Players* players;

    Game();
    ~Game();
    
    void outputText(string text, int posX, int posY, SDL_Texture **t, SDL_Color color);

    void init(const char* title, int width, int height);
    void handleEvent();
    void update(int frameCounter);
    void render();
    void clean();
    bool isRunning();
    void tryMatchCommand(int movement);

    static SDL_Renderer *renderer;
    static SDL_Event event;
};

#endif