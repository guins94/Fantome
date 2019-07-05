#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FANTOMESTATE_HEADER
#define FANTOMESTATE_HEADER

class FantomeState : public State
{
	private:
		bool quitRequested;
		Music backgroundMusic;
		Sprite* bg;
		bool started;
		bool popRequested;
		std::vector<std::shared_ptr<GameObject>> objectArray;
	public:
    Vec2 PlayerPosition = Vec2(0,0);
    bool fantomeExist = false;
    bool isAlive = true;
		int nFire = 0;
    int checkID = 0;
  private:
		void StartArray();
	  void UpdateArray(float dt);
		void RenderArray();
    void Input();
	public:
		FantomeState();
  public:
    ~FantomeState();
  public:
    bool QuitRequested();
  public:
    void LoadAssets();
  public:
    void Update();
  public:
    void Render();
	public:
		void Start();
	public:
		void AddObject(int mouseX,int mouseY);
	public:
		std::weak_ptr< GameObject > AddObject(GameObject* go);
	public:
		std::weak_ptr< GameObject > GetObjectPtr(GameObject* go);
	public:
		bool PopRequested();
	public:
		void Pause ();
	public:
		void Resume ();
  public:
    bool WillCollideWithGround(Rect& objectBox, float angleRad);
    bool WillCollideWithGrave(Rect& objectBox, float angleRad);
};

#endif
