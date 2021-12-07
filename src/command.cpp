#include "../include/command.h"

Command::Command(int value, const char* image) :  Sprite::Sprite(image){

    startTime = SDL_GetTicks();
    this->value = (position)value; 
    this->actualState = VALID;
}

Command* Command::generateCommand()
{
    //Pega um comando aleatorio
    const char* image;
    int i = rand()%4;
    if(i == 0)image = "assets/arrow.png";
    else if(i == 1) image = "assets/arrow1.png";
    else if(i == 2) image = "assets/arrow2.png";
    else image = "assets/arrow3.png";

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

   target();
   destroy();
}

void Command::target(){
    if(x >= (WINDOW_WIDTH/2)-64 && (x+64) < (WINDOW_WIDTH/2)+64 && actualState != INVALID) actualState = TARGET;
    else if((x+64) >= (WINDOW_WIDTH/2)+64)
    {
        actualState = INVALID;
        //if(value == POS_UP) changeImage("assets/VermelhaCima.png");
        //else if(value == POS_DOWN) changeImage("assets/VermelhaBaixo.png");
        //else if(value == POS_LEFT)changeImage("assets/VermelhaEsquerda.png");
        //else changeImage("assets/VermelhaDireita.png");
    }
}
void Command::destroy(){

    if(x >= WINDOW_WIDTH) actualState = DESTROY;
}