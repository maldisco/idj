#ifndef TILESET_H
#define TILESET_H

#include "Sprite.h"

class TileSet{
    public:
        TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file);

        void RenderTile(unsigned index, float x, float y);

        int GetTileWidth();

        int GetTileHeight();
    
    private:
        Sprite tileSet;
        int rows, columns;
        int tileHeight, tileWidth;
};
#endif