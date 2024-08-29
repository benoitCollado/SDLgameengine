#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "Components.hpp"
#include <SDL.h>
#include "../TextureManager.hpp"

class SpriteComponent: public Component{

private:
  PositionComponent *position;
  SDL_Texture* texture;

  SDL_Rect source_Rect, destination_Rect;

public:

  SpriteComponent()=default;
  SpriteComponent(const char* path){
    setTexture(path);
  }
  ~SpriteComponent()=default;

  void setTexture(const char* path){
    texture = TextureManager::loadTexture(path);
  }

  void init() override{

    position = &entity->getComponent<PositionComponent>();
    
    source_Rect.x = source_Rect.y = 0;
    source_Rect.w = source_Rect.h = 32;
    destination_Rect.h = destination_Rect.w = 32;
  }
  void update() override{
    destination_Rect.x = position->x();
    destination_Rect.y = position->y();
  }
  void draw() override{
    TextureManager::drawTexture(texture, &source_Rect, &destination_Rect);
    
    //std::cout << "SpriteComponent::draw() called" << std::endl;
  }

};

#endif

