#include "TextureManager.hpp"

SDL_Texture *TextureManager::loadTexture(const char *fileName, SDL_Renderer *renderer){
  SDL_Surface* temporary_Surface = IMG_Load(fileName);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temporary_Surface);
  SDL_FreeSurface(temporary_Surface);
  return texture;
}