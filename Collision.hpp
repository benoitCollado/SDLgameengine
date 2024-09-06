#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SDL.h>
#include "ECS/Components.hpp"

class Collision{
public:
  static bool AABB(const SDL_Rect& a, const SDL_Rect& b);

  static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};

#endif