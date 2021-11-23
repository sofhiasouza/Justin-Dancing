#include "../include/command.h"

Command::Command(int value, const char* image) :  Sprite::Sprite(image){

    startTime = SDL_GetTicks();
    this->value = value; 
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

}
