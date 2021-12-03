#include "../include/texture.h"

#include "../include/game.h"

SDL_Texture* Texture::loadTexture(const char* path){

    //carrega a imagem pra texture
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}

SDL_Texture* Texture::loadJustinTexture(const char* path){

    //carrega a imagem pra texture
    SDL_Surface *justin = IMG_Load(path);
    SDL_Texture *justinTexture = SDL_CreateTextureFromSurface(Game::renderer, justin);
    SDL_FreeSurface(justin);

    return justinTexture;
}

void Texture::render(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

void Texture::renderJustin(SDL_Texture *tex){
    SDL_Rect rect;
    rect.x = 10; //Extreme left of the window
    rect.y = 0; //Very bottom of the window
    rect.w = 80; //100 pixels width
    rect.h = 100; 
    SDL_RenderCopy(Game::renderer, tex, &rect, &rect);
}

