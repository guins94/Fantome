#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TILESET_HEADER
#define TILESET_HEADER

class TileSet{
	private:
		Sprite* tileSet;
		int rows;
		int columns;
		int tileWidth;
		int tileHeight;
	public:
		TileSet(int tileWidth, int tileHeight, std::string file);
	public:
		void RenderTile(unsigned index,float x,float y );
	public:
		int GetTileWidth();
		int GetTileHeight();
    int GetRows();
    int GetColumns();
};

#endif
