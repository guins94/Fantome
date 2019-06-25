#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef SPRITE_HEADER
#define SPRITE_HEADER

class Sprite : public Component{
	private:
		SDL_Texture* texture;
		int width;
		int height;
		SDL_Rect clipRect;
		Vec2 scale = Vec2(1,1);
		int frameCount;
		int currentFrame;
		float timeElapsed;
		float frameTime;
		Timer selfDestructCount;
    bool isRenderEnabled, isFlipped;
	public:
		float secondsToSelfDestruct;
	public:
		Sprite();
	public:
		 Sprite(std::string file);
	public:
		Sprite(GameObject* associated, int frameCount=1,float frameTime = 1);
	public:
		~Sprite();
	public:
		void Open(std::string file);
	public:
		void SetClip(int x, int y,int w,int h);
	public:
		void Render();
	public:
		void Start();
	public:
		void Render(float x, float y);
	public:
		void Update(float dt);
	public:
		int GetWidth();
	public:
		int GetHeight();
	public:
		bool IsOpen();
	public:
		bool Is(std::string type);
    void EnableRender();
    void DisableRender();
    void EnableFlip();
    void DisableFlip();
	public:
		void SetScaleX(float scaleX);
	public:
		void SetScaleY(float scaleY);
	 public:
		 Vec2 GetScale();
	 public:
		 void SetFrame(int frame);
	 public:
		 void SetFrameCount(int frameCount);
	 public:
		 void SetFrameTime(float frameTime);
};

#endif
