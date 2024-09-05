#include "Game.hpp"
#include "Collision.hpp"
#include "ECS/Components.hpp"
#include "Map.hpp"
#include "TextureManager.hpp"
#include <SDL_render.h>

Map *map;

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());
int nb_update = 0;

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
  player.addComponent<TransformComponent>(100, 150, 32, 32, 1);
  player.addComponent<SpriteComponent>("images/player.png");
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");

  wall.addComponent<TransformComponent>(150.f, 150.f, 20, 300, 1);
  wall.addComponent<SpriteComponent>("images/grass.png");
  wall.addComponent<ColliderComponent>("wall");

  // std::cout << getComponentTypeID<KeyboardController>() << std::endl;
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

  /*if (count % 90 == 0) {
    growing = !growing;
    std::cout << "switch" << std::endl;
  }
  if (growing) {
    player.getComponent<TransformComponent>().scale =
        1.f + (float)(3.f * (count % 90 / 89.f));
    std::cout << "growing : " << 1.f + (float)(3.f * (count % 90 / 89.f))
              << std::endl;
  } else {
    player.getComponent<TransformComponent>().scale =
        4.f - (float)(3.f * (count % 90 / 89.f));
    std::cout << "not growing : " << 4.f - (float)(3.f * (count % 90 / 89.f))
              << std::endl;
    std::cout << "right member : " << (float)(3.f * (count % 90 / 89.f))
              << std::endl;
  }*/

  /*std::cout << "player : "<<
  player.getComponent<ColliderComponent>().collider.x << std::endl; std::cout <<
  "player : "<< player.getComponent<ColliderComponent>().collider.y <<
  std::endl; std::cout << "player : "<<
  player.getComponent<ColliderComponent>().collider.w << std::endl; std::cout <<
  "player : "<< player.getComponent<ColliderComponent>().collider.h <<
  std::endl; std::cout << "wall : "<<
  wall.getComponent<ColliderComponent>().collider.x << std::endl; std::cout <<
  "wall : "<< wall.getComponent<ColliderComponent>().collider.y << std::endl;
  std::cout << "wall : "<< wall.getComponent<ColliderComponent>().collider.w <<
  std::endl; std::cout << "wall : "<<
  wall.getComponent<ColliderComponent>().collider.h << std::endl;*/

  if (Collision::AABB(player.getComponent<ColliderComponent>().collider,
                      wall.getComponent<ColliderComponent>().collider)) {
    player.getComponent<TransformComponent>().velocity *= -1.f;
    /*std::cout << "Wall Hit ! " << nb_update << std::endl;
    nb_update++;*/
  }

  // SDL_RenderClear(Game::renderer);

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
  SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
  SDL_RenderDrawRect(renderer,
                     &player.getComponent<ColliderComponent>().collider);
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  SDL_RenderDrawRect(renderer,
                     &wall.getComponent<ColliderComponent>().collider);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned ..." << std::endl;
}

bool Game::running() { return isRunning; }