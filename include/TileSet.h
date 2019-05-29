#pragma once

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
	public:
		int GetTileHeight();

};
