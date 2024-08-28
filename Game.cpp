#include "Game.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject *player;
GameObject *player2;

SDL_Renderer* Game::renderer = nullptr;

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
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created ... " << std::endl;
    }

    // playerText = TextureManager::loadTexture("images/player.png", renderer);
    isRunning = true;
  } else {
    isRunning = false;
  }
  player = new GameObject("images/player.png", 0, 0);
  player2 = new GameObject("images/player.png", 64, 64);
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
  player->update();
  player2->update();
  std::cout << count << std::endl;
}

void Game::render() {
  SDL_RenderClear(renderer);
  // this is where we would add stuff to render
  // SDL_RenderCopy(renderer, playerText, NULL, &destR);
  player->render();
  player2->render();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned ..." << std::endl;
}

bool Game::running() { return isRunning; }