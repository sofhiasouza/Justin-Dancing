#include "../include/command.h"

Command::Command(int value, const char* image) :  Sprite::Sprite(image){

    startTime = SDL_GetTicks();
    this->value = value; 
    this->actualState = VALID;
}

Command* Command::generateCommand()
{
    //Pega um comando aleatorio
    const char* image;
    int i = rand()%4;

    if(i == 0) image = "images/arrow.png";
    else if(i == 1) image = "images/arrow1.png";
    else if(i == 2) image = "images/arrow2.png";
    else image = "images/arrow3.png";

    return new Command(i, image);
}

void Command::render(){
    // Renderizando sprite
    Sprite::render();
}

void Command::update(){
   
   x++;

   srcRect.h = 32;
   srcRect.w = 32;
   srcRect.x = 0;
   srcRect.y = 0;

   destRect.x = x;
   destRect.y = y;
   destRect.w = srcRect.w * 2;
   destRect.h = srcRect.h * 2;

   destroy();
}

void Command::destroy(){

    if(x >= WINDOW_WIDTH) actualState = DESTROY;
}