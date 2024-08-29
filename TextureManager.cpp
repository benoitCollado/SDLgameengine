#include "TextureManager.hpp"

SDL_Texture *TextureManager::loadTexture(const char *fileName){
  SDL_Surface* temporary_Surface = IMG_Load(fileName);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temporary_Surface);
  SDL_FreeSurface(temporary_Surface);
  return texture;
}

void TextureManager::drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination){
  SDL_RenderCopy(Game::renderer, texture, source, destination);
}