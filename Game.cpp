#include "Game.hpp"
#include "ECS/Components.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"

Map *map;

SDL_Renderer *Game::renderer = nullptr;

Manager manager;
auto &player(manager.addEntity());
PositionComponent *position;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int posx, int posy, int width, int height,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized ... " << std::endl;

    window = SDL_CreateWindow(title, posx, posy, width, height, flags);
    if (window) {
      std::cout << "Window Created ... " << std::endl;
    }
    Game::renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created ... " << std::endl;
    }

    // playerText = TextureManager::loadTexture("images/player.png", renderer);
    isRunning = true;
  } else {
    isRunning = false;
  }

  map = new Map();
  player.addComponent<PositionComponent>(100,150);
  position = &player.getComponent<PositionComponent>();
  std::cout << position->x() << "," << position->y() << std::endl;
  player.addComponent<SpriteComponent>("images/player.png");
  std::cout << getComponentTypeID<SpriteComponent>() << std::endl;
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::update() {
  count++;
  manager.update();

  if(player.getComponent<PositionComponent>().x() > 200){
    player.getComponent<SpriteComponent>().setTexture("images/water.png");
    player.getComponent<PositionComponent>().setPosition(50,50);
  }
  /*std::cout<<newPlayer.getComponent<PositionComponent>().x() <<  " , " <<
  newPlayer.getComponent<PositionComponent>().y() << std::endl; std::cout <<
  count << std::endl;*/
}

void Game::render() {
  SDL_RenderClear(renderer);
  // this is where we would add stuff to render
  // SDL_RenderCopy(renderer, playerText, NULL, &destR);
   map->drawMap();
  manager.draw();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned ..." << std::endl;
}

bool Game::running() { return isRunning; }