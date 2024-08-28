#ifndef Game_hpp
#define Game_hpp

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>

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

  static SDL_renderer* renderer;

private: 
  int count = 0;
  bool isRunning;
  SDL_Window *window;

};


#endif