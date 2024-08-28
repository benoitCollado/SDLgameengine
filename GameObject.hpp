#include "Game.hpp"

class GameObject{

public:
  GameObject(const char* texture_sheet, SDL_Renderer* renderer, int x, int y);
  ~GameObject();

    void update();
    void render();
  

private: 
  int x_position;
  int y_position;

  SDL_Texture* object_texture;
  SDL_Rect source_Rect, destination_Rect;
  SDL_Renderer* renderer;


};