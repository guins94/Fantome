#pragma once


class ParallaxScrolling : public Component{
	private:
    std::vector<int> tileMatrix;
		Sprite* tileSet;
		int mapWidth;
		int mapHeight;
		int mapDepth;
    float multiplier;
	public:
		ParallaxScrolling(GameObject* associated,float multiplier,std::string sprite_file, std::string file);
	public:
    int* At(int x,int y, int z);
  public:
    void Load(std::string file);
  public:
    void RenderLayer(int layer, int cameraX, int CameraY);
  public:
    void SetTileSet(Sprite* tileSet);
  public:
		void Render();
	public:
		void Start();
	public:
		void Update(float dx);
	public:
		bool Is(std::string type);
  public:
    void RenderTile(unsigned index,float x,float y );
};
