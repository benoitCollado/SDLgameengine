#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "Components.hpp"
#include <SDL.h>
#include "../TextureManager.hpp"

class SpriteComponent: public Component{

private:
  TransformComponent *transform;
  SDL_Texture* texture;

  SDL_Rect source_Rect, destination_Rect;

public:

  SpriteComponent()=default;
  SpriteComponent(const char* path){
    setTexture(path);
  }
  ~SpriteComponent(){
    SDL_DestroyTexture(texture);
  };

  void setTexture(const char* path){
    texture = TextureManager::loadTexture(path);
  }

  void init() override{

    transform = &entity->getComponent<TransformComponent>();
    
    source_Rect.x = source_Rect.y = 0;
    source_Rect.w = transform->width;
    source_Rect.h = transform->height;
 
  }
  void update() override{
    destination_Rect.x = (int)transform->position.x;
    destination_Rect.y = (int)transform->position.y;
    destination_Rect.h = source_Rect.h * transform->scale;
    destination_Rect.w = source_Rect.w * transform->scale;
  }
  void draw() override{
    TextureManager::drawTexture(texture, &source_Rect, &destination_Rect);
    
    //std::cout << "SpriteComponent::draw() called" << std::endl;
  }

};

#endif

