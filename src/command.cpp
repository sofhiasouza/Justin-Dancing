#include "../include/command.h"

Command::Command(int value, const char* image) :  Sprite::Sprite(image){

    startTime = SDL_GetTicks();
    this->value = (position)value; 
    this->actualState = VALID;
    this->flagFailureP1 = 0;
    this->flagFailureP2 = 0;

}

Command* Command::generateCommand()
{
    //Pega um comando aleatorio
    const char* image;
    int i = rand()%4;
    if(i == 0)image = "assets/AmarelaCima.png";
    else if(i == 1) image = "assets/AmarelaBaixo.png";
    else if(i == 2) image = "assets/AmarelaEsquerda.png";
    else image = "assets/AmarelaDireita.png";

    return new Command(i, image);
}

void Command::render(){
    // Renderizando sprite
    Sprite::render();
}

void Command::update(pthread_mutex_t mutex){
   
   x+=2; // Move Sprite

   srcRect.h = 32;
   srcRect.w = 32;
   srcRect.x = 0;
   srcRect.y = 0;

   destRect.x = x;
   destRect.y = WINDOW_HEIGHT-80;
   destRect.w = srcRect.w * 2;
   destRect.h = srcRect.h * 2;

   changeState();
}

void Command::changeImageSprite(const char* pathCommands){
    changeImage(pathCommands);
}

void Command::changeState(){

    if(x >= (WINDOW_WIDTH/2)-64 && (x+64) < (WINDOW_WIDTH/2)+64 && actualState != INVALID) actualState = TARGET;
    if((x+64) >= (WINDOW_WIDTH/2)+64)
    {
        std::cout << "nao entra qqui" << std::endl;
        actualState = INVALID;
    }
    if(x >= WINDOW_WIDTH)
    {
        SDL_DestroyTexture(textureCommands);
        actualState = DESTROY;
    }
    if(flagPointP1 == 1)
    {
        if(value == 0)changeImage("assets/VerdeCima.png");
        else if(value == 1) changeImage("assets/VerdeBaixo.png");
        else if(value == 2) changeImage("assets/VerdeEsquerda.png");
        else changeImage("assets/VerdeDireita.png");
        flagPointP1 = 2;
    }
    else if(flagPointP2 == 1)
    {
        if(value == 0)changeImage("assets/AzulCima.png");
        else if(value == 1) changeImage("assets/AzulBaixo.png");
        else if(value == 2) changeImage("assets/AzulEsquerda.png");
        else changeImage("assets/AzulDireita.png");
        flagPointP2 = 2;
    }
    else if (actualState == INVALID && flagPointP1 != 2 && flagPointP2 != 2)
    {
        if(value == 0)changeImage("assets/VermelhaCima.png");
        else if(value == 1) changeImage("assets/VermelhaBaixo.png");
        else if(value == 2) changeImage("assets/VermelhaEsquerda.png");
        else changeImage("assets/VermelhaDireita.png");
        flagPointP1 = 2;
    }
    
}
