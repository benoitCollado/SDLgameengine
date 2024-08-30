#ifndef KEYBOARDCONTROLLER_HPP
#define KEYBOARDCONTROLLER_HPP

#include "../Game.hpp"
#include "Components.hpp"

class KeyboardController: public Component{
public:
  TransformComponent* transform;

  void init() override{
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override{
    if(Game::event.type == SDL_KEYDOWN){
      switch(Game::event.key.keysym.sym){
        case SDLK_z:
          transform->velocity.y = -1;
          break;
        case SDLK_s:
          transform->velocity.y = 1;
          break;
        case SDLK_q:
          transform->velocity.x = -1;
          break;
        case SDLK_d:
          transfrom->velocity.x = 1;
          break;
        default:
          break;
      }
    }

    if(Game::event.type == SDL_KEYUP){
        switch(Game::event.key.keysym.sym){
          case SDLK_z:
            transform->velocity.y = 0;
            break;
          case SDLK_s:
            transform->velocity.y = 0;
            break;
          case SDLK_q:
            transform->velocity.x = 0;
            break;
          case SDLK_d:
            transfrom->velocity.x = 0;
            break;
          default:
            break;
        }
    }
  }
}

#endif