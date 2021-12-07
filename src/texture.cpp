#include "../include/texture.h"

#include "../include/game.h"

SDL_Texture* Texture::loadTexture(const char* path){

    //carrega a imagem pra texture
    SDL_Surface* tempSurface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return texture;
}

void Texture::renderCommands(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

void Texture::renderJustins(SDL_Texture *tex1, SDL_Texture *tex2){
    SDL_Rect rect, clip;
    clip.h = 100;
    clip.w = 80;
    clip.x = 0;
    clip.y = 0;

    rect.x = 140;
    rect.y = WINDOW_HEIGHT-500;
    rect.w = clip.w ;
    rect.h = clip.h ;
    SDL_RenderCopy(Game::renderer, tex1, &clip, &rect);

    clip.h = 100;
    clip.w = 80;
    clip.x = 0;
    clip.y = 0;

    rect.x = WINDOW_WIDTH - 140;
    rect.y = WINDOW_HEIGHT-500;
    rect.w = clip.w ;
    rect.h = clip.h ;
    SDL_RenderCopy(Game::renderer, tex2, &clip, &rect);
}

void Texture::renderBG(SDL_Texture *tex1){
    SDL_Rect rect, clip;
    clip.h = 640;
    clip.w = 800;
    clip.x = 0;
    clip.y = 0;

    rect.x = 0;
    rect.y = 0;
    rect.w = 840;
    rect.h = 640;
    SDL_RenderCopy(Game::renderer, tex1, &clip, &rect);
}

