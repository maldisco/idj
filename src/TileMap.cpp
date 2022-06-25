#include "TileMap.h"
#include "iostream"
#include "fstream"
#include "sstream"


TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) : tileSet(tileSet), Component(associated){
    Load(file);
}

void TileMap::Load(std::string file){
    std::fstream map;
    std::vector<int> dims;

    map.open("assets/map/tileMap.txt");
    if(map.is_open()){
        std::string line;
        
        getline(map, line);
        std::stringstream ss(line);

        // extract map dimension from 1st line
        for(int i; ss >> i;){
            dims.push_back(i);
            if(ss.peek() == ',')
                ss.ignore();
        }
        mapWidth = dims[0];
        mapHeight = dims[1];
        mapDepth = dims[2];

        std::cout << "Largura: " << mapWidth << "\n";
        std::cout << "Altura: " << mapHeight << "\n";
        std::cout << "Profundidade: " << mapDepth << "\n";
    }
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    return tileMatrix[625*z + 25*y + x];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){

}

void TileMap::Render(){

}

int TileMap::GetDepth(){ return mapDepth; }
int TileMap::GetWidth(){ return mapWidth; }
int TileMap::GetHeight(){ return mapHeight; }