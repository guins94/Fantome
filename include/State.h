#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef STATE_HEADER
#define STATE_HEADER

class State
{
	private:
		bool quitRequested;
		Music* music;
		Sprite* bg;
		bool started;
		bool popRequested;
		std::vector< std::shared_ptr<GameObject>> objectArray;
  private:
		void StartArray();
	  void virtual UpdateArray(float dt) = 0;
		void virtual RenderArray() = 0;
    void Input();
	public:
		State();
  public:
    virtual ~State() = 0;
  public:
    bool GetQuitRequested();
  public:
    void QuitRequested();
  public:
    void LoadAssets();
  public:
    void virtual Update() = 0;
  public:
    void virtual Render() = 0;
	public:
		void virtual Start() = 0;
	public:
		std::weak_ptr< GameObject > virtual AddObject(GameObject* go) = 0;
	public:
		std::weak_ptr< GameObject > virtual GetObjectPtr(GameObject* go)= 0;
	public:
		bool GetPopRequested();
  public:
    void PopRequested();
	public:
		void virtual Pause () = 0;
	public:
		void virtual Resume () = 0;
};

#endif
