#include "Collision.hpp"
#include <iostream>

bool Collision::AABB(const SDL_Rect &a, const SDL_Rect &b) {
  if (
    b.x >= a.x + a.w|| 
    b.x + b.w <= a.x ||
    b.y >= a.y + a.h ||
    b.y + b.h <= a.y
    ) {
    return false;
  }

  return true;
}

bool Collision::AABB(const ColliderComponent &colA, const ColliderComponent &colB){
  if(AABB(colA.collider, colB.collider)){
    std::cout << colA.tag << " Hit " << colB.tag << std::endl;
    return true;
    
  }
  return false;
}