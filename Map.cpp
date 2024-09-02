#include "Map.hpp"

int level1[10][15] = {
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
  {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0},
  {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0},
  {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0},
  {0,0,0,0,2,1,1,1,1,2,0,0,0,0,0},
  {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map(){
  dirt_Texture = TextureManager::loadTexture("images/dirt.png");
  grass_Texture = TextureManager::loadTexture("images/grass.png");
  water_Texture = TextureManager::loadTexture("images/water.png");

  loadMap(level1);

  source_Rect.h = source_Rect.w = 32;
  source_Rect.x = source_Rect.y = 0;
  destination_Rect.w = destination_Rect.h = 32;
  
}

Map::~Map(){
  SDL_DestroyTexture(dirt_Texture);
  SDL_DestroyTexture(grass_Texture);
  SDL_DestroyTexture(water_Texture);
}

void Map::loadMap(int arr[10][15]){
  for(int row = 0; row < 10; row++){
    for(int col = 0; col < 15; col++){
      map_Tiles[row][col] = arr[row][col];
    }
  }
}

void Map::drawMap(){
  int type = 0;
  for(int row = 0; row < 10; row++){
    for(int col = 0; col < 15; col++){
      type = map_Tiles[row][col];
      
      destination_Rect.x = 32 * col;
      destination_Rect.y = 32 * row;

      
      switch(type){
        case 0:
          TextureManager::drawTexture(water_Texture, &source_Rect, &destination_Rect);
          break;
        case 1:
          TextureManager::drawTexture(grass_Texture, &source_Rect, &destination_Rect);
          break;
        case 2:
          TextureManager::drawTexture(dirt_Texture, &source_Rect, &destination_Rect);
          break;
        default:
          break;
      }
    }
  }
}