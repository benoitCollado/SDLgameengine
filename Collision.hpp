#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <SDL.h>

class Collision{

  static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
};

#endif