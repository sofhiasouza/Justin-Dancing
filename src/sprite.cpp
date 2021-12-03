#include "../include/sprite.h"

Sprite::Sprite(){
    x = 0;
    y = 0;    
}

Sprite::Sprite(const char* path, const char* path2){
    
    texture = Texture::loadTexture(path);
    texture2 = Texture::loadJustinTexture(path2);
    x = 0;
    y = 0;
}

void Sprite::render(){
    Texture::render(texture, srcRect, destRect);
    Texture::renderJustin(texture2);
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

