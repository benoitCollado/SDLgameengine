#include "Map.hpp"
#include "Game.hpp"
#include <fstream>

Map::Map(){

  
}

Map::~Map(){

}

void Map::loadMap(std::string path, int sizeX, int sizeY){

  char tile;
  std::fstream mapFile;
  mapFile.open(path);

  for(int y = 0; y < sizeY; y++){
    for(int x = 0; x < sizeX; x++){
      mapFile.get(tile);
      Game::Addtile(atoi(&tile), x*32, y*32);
      mapFile.ignore();
    }
  }

  mapFile.close();
}

