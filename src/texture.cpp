#include "../include/texture.h"

SDL_Texture* Texture::loadTexture(const char* path, SDL_Renderer renderer){

    //carrega a imagem pra texture
    SDL_Surface* tempSurface = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}