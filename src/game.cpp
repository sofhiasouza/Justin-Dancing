#include "../include/game.h"

SDL_Renderer* Game::renderer = nullptr;

SDL_Texture* player1;

SDL_Event Game::event;

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

    commands.push_back(Command::generateCommand());
    targetCommandIterator = commands.begin();
    players = new Players();
}

void Game::handleEvent(){

    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            run = false;
            break;

        case(SDL_KEYDOWN):

            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    run = false;
                    break;
            }

            break;
        default:
            break;
    }

     switch (event.type){
        case SDL_QUIT:
            run = false;
            break;
        
        default:
            break;
    }
}

void Game::update(int frameCounter){

    if(frameCounter % 600 == 0) commands.push_back(Command::generateCommand());

    if(frameCounter % 2 == 0){
        // Movimenta comandos
        for(commandsIterator = commands.begin(); commandsIterator != commands.end(); commandsIterator++)
            (*commandsIterator)->update();
        
        // Exclui comandos que sairam da tela
        if((*commands.begin())->actualState == DESTROY)
          commands.erase(commands.begin()); 
    }


    if((*targetCommandIterator)->actualState == TARGET)
    {
        // IMPLEMENTAR THREADS AQUI
        players->tryMatchP1(event,(*targetCommandIterator));
        players->tryMatchP2(event,(*targetCommandIterator));
    }
    else if((*targetCommandIterator)->actualState == INVALID)
    {
        targetCommandIterator++;
    }
}

void Game::render(){
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(renderer);    

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_RenderDrawLine(renderer, (WINDOW_WIDTH/2)-64, 0, (WINDOW_WIDTH/2)-64, 50);
    SDL_RenderDrawLine(renderer, (WINDOW_WIDTH/2)+64, 0, (WINDOW_WIDTH/2)+64, 50);

    for(commandsIterator = commands.begin(); commandsIterator != commands.end(); commandsIterator++)
        (*commandsIterator)->render();

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