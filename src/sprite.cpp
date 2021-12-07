#include "../include/sprite.h"
#include <iostream>

Sprite::Sprite(){
    x = 0;
    y = 0;    
}

Sprite::Sprite(const char* pathCommands){
    
    textureCommands = Texture::loadTexture(pathCommands);
    x = 0;
    y = 0;
}

void Sprite::changeImage(const char* pathCommands){
    textureCommands = Texture::loadTexture(pathCommands);
}

Sprite::Sprite(const char* pathJ1, const char* pathJ2, const char* pathBG){
    textureJ1 = Texture::loadTexture(pathJ1);
    textureJ2 = Texture::loadTexture(pathJ2);
    textureBG = Texture::loadTexture(pathBG);
    x = 0;
    y = 0;
}

void Sprite::render(){
    Texture::renderCommands(textureCommands, srcRect, destRect);
}

void Sprite::renderEnvironment(){
    Texture::renderBG(textureBG);
    Texture::renderJustins(textureJ1, textureJ2);    
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

