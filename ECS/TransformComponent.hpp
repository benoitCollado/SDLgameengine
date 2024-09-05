#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP
#include "Components.hpp"
#include "../Vector2D.hpp"


class TransformComponent: public Component{

public:

  Vector2D position;
  Vector2D velocity;
  Vector2D movment; 

  float speed = 2.f; 

  int height = 32;
  int width = 32;
  float scale = 1.f;
  

  TransformComponent(){
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(float x_init, float y_init){
    position.x = x_init;
    position.y = y_init;
  }

  TransformComponent(float x_init, float y_init, int h, int w, float sc){
    position.x = x_init;
    position.y = y_init;
    height = h;
    width = w;
    scale = sc;
    
  }

  float x() {return position.x;}
  void x(float x_init) {position.x = x_init;}
  float y() {return position.y;}
  void y(float y_init) {position.y = y_init;}

  void setPosition(float x, float y){
    position.x = x;
    position.y = y;
  }

  void update() override{
    movment.x = velocity.x;
    movment.y = velocity.y;
    movment.normalize();
    movment = movment * speed;
    position.x += movment.x;
    position.y += movment.y;

  }

  void init() override{
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    movment.x = 0.0f;
    movment.y = 0.0f;
  }

  bool isMoving() {
    if (movment.norme() != 0.0f){
      return true;
    }

    return false;
  }
~TransformComponent(){}

};
#endif
