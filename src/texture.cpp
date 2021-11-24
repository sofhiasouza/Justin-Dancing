#include "../include/texture.h"

#include "../include/game.h"

SDL_Texture* Texture::loadTexture(const char* path){

    //carrega a imagem pra texture
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}

void Texture::render(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
