#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP
#include "Components.hpp"
#include "../Vector2D.hpp"


class TransformComponent: public Component{

public:

  Vector2D position;
  Vector2D velocity;

  int speed = 3; 

  int height = 32;
  int width = 32;
  int scale = 1;
  

  TransformComponent(){
    position.x = 0.0f;
    position.y = 0.0f;
  }

  TransformComponent(float x_init, float y_init){
    position.x = x_init;
    position.y = y_init;
  }

  TransformComponent(float x_init, float y_init, int h, int w, int sc){
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
    //std::cout << "Velocity : " << velocity << std::endl;
    position.x += velocity.x * (float)speed;
    position.y += velocity.y * (float)speed;
  }

  void init() override{
    velocity.x = 0.0f;
    velocity.y = 0.0f;
  }
~TransformComponent(){}

};
#endif
