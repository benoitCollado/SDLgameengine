#ifndef COLLIDERCOMPONENT_HPP
#define COLLIDERCOMPONENT_HPP
#endif

#include <string>
#include <SDL.h>
#include "ECS.hpp"
#include <vector>

class ColliderComponent : public Component{

public:
  SDL_Rect collider;
  std::string tag;

  static std::vector<ColliderComponent*> colliders;
  
  TransformComponent* transform;

  ColliderComponent(std::string wTag){
    tag = wTag;
  }

  ~ColliderComponent(){};

  void init() override{
    if (!entity->hasComponent<TransformComponent>()){
      entity->addComponent<TransformComponent>();
    }

    transform = &entity->getComponent<TransformComponent>();
    
    ColliderComponent::colliders.push_back(this);
  }

  void update() override{
    collider.x = transform->position.x;
    collider.y = transform->position.y;
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
  }



};