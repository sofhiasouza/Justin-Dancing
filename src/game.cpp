#include "../include/game.h"

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char *title, int width, int height){

    // Inicializa SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Cria a janela
    windowHeight = height;
    windowWidth = width;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Cria o Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer == nullptr){
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Game::handleEvent(){

    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            run = false;
            break;
        
        default:
            break;
    }

}

void Game::update(){

}

void Game::render(){

    SDL_RenderClear(renderer);
    //here is stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    window = nullptr;
    renderer = nullptr;

    SDL_Quit();
}

bool Game::isRunning(){
    return run;
}