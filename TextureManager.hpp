#ifndef TextureManager_hpp
#define TextureManager_hpp
#include "Game.hpp"

class TextureManager{

public: 
  static SDL_Texture* loadTexture(const char* fileName);
  static void drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);

};
#endif /* TextureManager_hpp */