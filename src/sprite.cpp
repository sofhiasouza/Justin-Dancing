#include "../include/sprite.h"

Sprite::Sprite(){
    x = 0;
    y = 0;    
}

Sprite::Sprite(const char* path){
    
    texture = Texture::loadTexture(path);
    x = 0;
    y = 0;
}

void Sprite::render(){
    Texture::render(texture, srcRect, destRect);
}

void Sprite::setX(int x){
    this->x = x;
}

void Sprite::setY(int y){
    this->y = y;
}

void Sprite::setPos(int x, int y){
    this->x = x;
    this->y = y;
}

