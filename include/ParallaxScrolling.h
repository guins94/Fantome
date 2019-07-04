#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef PARALLAX_HEADER
#define PARALLAX_HEADER

class ParallaxScrolling : public Component
{
	private:
    std::vector<int> tileMatrix;
		Sprite* tileSet;
		int mapWidth, mapHeight, mapDepth;
    float multiplier;

	public:
		ParallaxScrolling(GameObject* associated,float multiplier,std::string sprite_file, std::string file);
    ParallaxScrolling(GameObject* associated, float multiplier, std::string sprite_file, std::string file, int frameCount);

    int* At(int x,int y, int z);

    void Load(std::string file);
    void RenderLayer(int layer, int cameraX, int CameraY);
    void SetTileSet(Sprite* tileSet);

		void Start();
		void Update(float dx);
    void Render();
		bool Is(std::string type);
    void RenderTile(unsigned index,float x,float y );
};

#endif
