#ifndef Game_hpp
#define Game_hpp


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <vector>
//#include "ECS/ColliderComponent.hpp"
//class ColliderComponent;
class Game{

public:
  Game();
  ~Game();

  void init(const char *title, int posx, int posy, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running();

  static SDL_Renderer* renderer;
  static SDL_Event event;
  static void Addtile(int id, int x, int y);
  
  //static std::vector<ColliderComponent*> colliders;
private: 
  int count = 0;
  //bool growing = true;
  bool isRunning;
  SDL_Window *window;

};


#endif