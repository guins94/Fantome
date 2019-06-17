#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef STAGESTATE_HEADER
#define STAGESTATE_HEADER

class StageState: public State{
	private:
		bool quitRequested;
		Music* music;
		Sprite* bg;
		bool started;
		bool popRequested;
		std::vector< std::shared_ptr<GameObject>> objectArray;
	public:
		int nAliens = 2;
  private:
		void StartArray();
	  void UpdateArray(float dt);
		void RenderArray();
    void Input();
	public:
		StageState();
  public:
    ~StageState();
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
};

#endif
