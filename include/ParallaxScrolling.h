#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef PARALLAX_HEADER
#define PARALLAX_HEADER

class ParallaxScrolling : public Component
{
	private:
		Sprite* parallaxSprite;
    float multiplier;

	public:
		ParallaxScrolling(GameObject* associated,float multiplier,std::string sprite_file);
    ParallaxScrolling(GameObject* associated, float multiplier, std::string sprite_file, int frameCount);

    void SetTileSet(Sprite* tileSet);

		void Start();
		void Update(float dx);
    void Render();
		bool Is(std::string type);
    void NotifyCollision();
};

#endif
