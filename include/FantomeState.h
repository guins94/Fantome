#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FANTOMESTATE_HEADER
#define FANTOMESTATE_HEADER

enum OrbState {YELLOW=1,  BLUE=0, RED= 2};

class FantomeState : public State
{
	private:
    Timer resetTimer;
		Music backgroundMusic;
		Sprite* bg;
		bool started;
		std::vector<std::shared_ptr<GameObject>> objectArray;

    void StartArray();
    void UpdateArray(float dt);
    void RenderArray();
    void Input();

	public:
    Vec2 PlayerPosition = Vec2(0,0);
    bool fantomeExist = false;
    bool isAlive = true;
		int nSoulStone = 0;
    int checkPointID = 0;
    int teleportID = 0;
    OrbState leftOrbState = BLUE;
    OrbState rightOrbState = BLUE;

	public:
		FantomeState();
    ~FantomeState();

    bool QuitRequested();
    bool PopRequested();

    void LoadAssets();
    void Update();
    void Render();
		void Start();
		void AddObject(int mouseX,int mouseY);

		std::weak_ptr<GameObject> AddObject(GameObject* go);
		std::weak_ptr<GameObject> GetObjectPtr(GameObject* go);


		void Pause();
		void Resume();

    bool WillCollideWithGround(Rect& objectBox, float angleRad);
    bool WillCollideWithGrave(Rect& objectBox, float angleRad);

    void AddHolyLight(int posX, int posY);
};

#endif
