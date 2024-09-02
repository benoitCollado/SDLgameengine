#include "Game.hpp"
#include "TextureManager.hpp"

#include <SDL.h>

class Map{

public:
  Map();
  ~Map();

  void loadMap(int arr[10][15]);
  void drawMap();

private:
  SDL_Rect source_Rect, destination_Rect;

  SDL_Texture* dirt_Texture;
  SDL_Texture* grass_Texture;
  SDL_Texture* water_Texture;

  int map_Tiles[10][15];


};