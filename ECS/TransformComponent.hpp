#ifndef POSITIONCOMPONENT_HPP
#define POSITIONCOMPONENT_HPP
#include "Components.hpp"


class TransformComponent: public Component{

private:
  int x_pos;
  int y_pos;

public:
  TransformComponent(){
    x_pos = 0;
    y_pos = 0;
  }

  TransformComponent(int x_init, int y_init){
    //std::cout << "PositionComponent constructor called" << std::endl;
    //std::cout << x_init << "," << y_init << std::endl;
    x_pos = x_init;
    y_pos = y_init;
  }

  int x() {return x_pos;}
  void x(int x_init) {x_pos = x_init;}
  int y() {return y_pos;}
  void y(int y_init) {y_pos = y_init;}

  void setPosition(int x, int y){
    x_pos = x;
    y_pos = y;
  }

  void update() override{
    x_pos++;
    y_pos++;
  }
~TransformComponent(){}

};
#endif
