#include "Game.hpp"
#include "ECS/Components.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"

Map *map;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto &player(manager.addEntity());

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
  player.addComponent<TransformComponent>(100, 150);
  player.addComponent<SpriteComponent>("images/player.png");
  player.addComponent<KeyboardController>();
   //std::cout << getComponentTypeID<KeyboardController>() << std::endl;
}

void Game::handleEvents() {

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