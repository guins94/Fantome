#pragma once

#include"TileSet.h"

class TileMap : public Component{
	private:
		std::vector<int> tileMatrix;
		TileSet* tileSet;
		int mapWidth;
		int mapHeight;
		int mapDepth;
	public:
		TileMap(GameObject* associated,std::string file,TileSet* tileSet);
	public:
		void Load(std::string file);
	public:
		void SetTileSet(TileSet* tileSet);
	public:
		int* At(int x,int y, int z);
	public:
		void Render();
	public:
		void Start();
	public:
		void RenderLayer(int layer, int cameraX, int CameraY);
	public:
		void Update(float dx);
	public:
		bool Is(std::string type);
	public:
		int GetWidth();
	public:
		int GetHeight();
	public:
		int GetDepth();
};
