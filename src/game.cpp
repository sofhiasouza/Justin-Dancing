#include "../include/game.h"


SDL_Renderer* Game::renderer = nullptr;

SDL_Texture* player1;

SDL_Event Game::event;

Game::Game(){
}

Game::~Game(){
}

void Game::init(const char *title, int width, int height){
    GameOver = false;
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
    environment = new Sprite("assets/J1.png", "assets/J2.jpg", "assets/background.jpg");
    targetCommandIterator = commands.begin();
    players = new Players();

    // Inicializando mutex
    pthread_mutex_init(&mutex, NULL);

    if (TTF_Init() < 0){
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    }

    font = TTF_OpenFont("./assets/font/stocky.ttf", 26);
    if (!font){
        cout << "Failed to load font: " << TTF_GetError() << endl;
    }
}

void Game::outputText(string text, int posX, int posY, SDL_Texture **texture, SDL_Color color)
{   
    if (*texture != nullptr) {
        SDL_DestroyTexture(*texture);
        *texture = nullptr;
    }

    // Criando textura a partir da fonte e do texto dado
    SDL_Surface *text_surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (text_surface == nullptr){
        std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        exit(-1);
    }

    *texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (*texture == nullptr){
        std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    int src_width = text_surface->w;
    int src_height = text_surface->h;

    SDL_FreeSurface(text_surface);

    SDL_Rect clip = {0, 0, src_width, src_height};
    SDL_Rect rect = {posX, posY, src_width, src_height};

    SDL_RenderCopy(renderer, *texture, &clip, &rect);
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

    if(frameCounter % 100 == 0) commands.push_back(Command::generateCommand());

    if(frameCounter % 2 == 0){

        //Entrando na região crítica
        pthread_mutex_lock(&mutex);

        // Movimenta comandos
        for(commandsIterator = commands.begin(); commandsIterator != commands.end(); commandsIterator++)
            (*commandsIterator)->update(mutex);

        // Exclui comandos que sairam da tela
        if((*commands.begin())->actualState == DESTROY){
          Command *deletedCommand = *commands.begin(); 
          commands.erase(commands.begin()); 
          delete deletedCommand;
        }

        if((*targetCommandIterator)->actualState == INVALID)
        {        
            targetCommandIterator++;
        }  
    
        // Saindo da região crítica
        pthread_mutex_unlock(&mutex);
    }
}

void Game::tryMatchCommand(int movement){

    if((*targetCommandIterator)->actualState == TARGET)
    {
        players->tryMatch(movement,&(*targetCommandIterator));
    }
    if((*targetCommandIterator)->actualState == INVALID)
    {        
        targetCommandIterator++;
    }  
}

void Game::render(){
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderClear(renderer);    

    environment->renderEnvironment();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    
    outputText("PLAY! ", (WINDOW_WIDTH/2)-40, WINDOW_HEIGHT-100, &t1, {255,255,255,255});
    SDL_RenderDrawLine(renderer, (WINDOW_WIDTH/2)-64, WINDOW_HEIGHT-70, (WINDOW_WIDTH/2)-64, WINDOW_HEIGHT-10);
    SDL_RenderDrawLine(renderer, (WINDOW_WIDTH/2)+64, WINDOW_HEIGHT-70, (WINDOW_WIDTH/2)+64, WINDOW_HEIGHT-10);

    outputText("Justin 1 points: ", 70, 320, &t2, {255,255,255,255});
    outputText(to_string(players->pointsP1), 180, 360, &t3, {0,255,0,255});
    outputText("Remaining failures: ", 40, 400, &t4, {255,255,255,255});
    outputText(to_string(players->failuresP1), 180, 450, &t5, {255,255,255,255});
    
    outputText("Justin 2 points: ", WINDOW_WIDTH-260, 320, &t6, {255,255,255,255});
    outputText(to_string(players->pointsP2), WINDOW_WIDTH-130, 360, &t7, {0,0,255,255});
    outputText("Remaining failures: ", WINDOW_WIDTH-300, 400, &t8, {255,255,255,255});
    outputText(to_string(players->failuresP2), WINDOW_WIDTH-130, 450, &t9, {255,255,255,255});

    for(commandsIterator = commands.begin(); commandsIterator != commands.end(); commandsIterator++)
        (*commandsIterator)->render();

    

    if(players->pointsP1 == 30)
    {
        GameOver = true;
        outputText("Justin 1 WON!", WINDOW_WIDTH/2 - 80, 320, &t10, {255,255,255,255});
    }
    else if(players->pointsP2 == 30)
    {
        GameOver = true;
        outputText("Justin 2 WON!", WINDOW_WIDTH/2 - 80, 320, &t10, {255,255,255,255});
    }
    else if(players->failuresP1 == 10)
    {
        GameOver = true;
        outputText("Justin 1 Loose!", WINDOW_WIDTH/2 - 80, 320, &t10, {255,255,255,255});
    }
    else if(players->failuresP2 == 10)
    {
        GameOver = true;
        outputText("Justin 2 Loose!", WINDOW_WIDTH/2 - 80, 320, &t10, {255,255,255,255});
    }

    SDL_RenderPresent(renderer);

}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    window = nullptr;
    renderer = nullptr;

    // Destruindo mutex
    pthread_mutex_destroy(&mutex);

    SDL_Quit();
}

bool Game::isRunning(){
    return run;
}