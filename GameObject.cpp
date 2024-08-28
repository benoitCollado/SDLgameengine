#include "GameObject.hpp"
#include "TextureManager.hpp"
GameObject::GameObject(const char *textureSheet, int x,int y) {
  object_texture = TextureManager::loadTexture(textureSheet);
  x_position = x;
  y_position = y;
}

void GameObject::update() {
  x_position++;
  y_position++;

  source_Rect.h = 32;
  source_Rect.w = 32;
  source_Rect.x = 0;
  source_Rect.y = 0;

  destination_Rect.h = 32;
  destination_Rect.w = 32;
  destination_Rect.x = x_position;
  destination_Rect.y = y_position;
}

void GameObject::render() {
  SDL_RenderCopy(Game::renderer, object_texture, &source_Rect, &destination_Rect);
}