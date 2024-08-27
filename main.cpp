#include "Game.hpp"

Game *game = nullptr;

int main (int argc, const char * argv[]){
  game = new Game();
  game->init("New engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 300, false);
  //mainloop
  while (game->running()){
    //handle any user input
    //update all object, positionsn etc.
    // render changes to the display
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();

  return 0;
}