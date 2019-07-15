#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef STATE_HEADER
#define STATE_HEADER

class State
{
  protected:
    bool popRequested;
    bool quitRequested;
    bool started;
    std::vector<std::shared_ptr<GameObject>> objectArray;

    void StartArray();
    void virtual UpdateArray(float dt);
    void virtual RenderArray();

	public:
		State();
    virtual ~State();

    bool GetQuitRequested();
    bool GetPopRequested();

    void QuitRequested();
    void PopRequested();

    void LoadAssets();

		void virtual Start() = 0;
    void virtual Update() = 0;
    void virtual Render() = 0;
		void virtual Pause() = 0;
		void virtual Resume() = 0;
    virtual std::weak_ptr<GameObject> AddObject(GameObject* go) = 0;
    virtual std::weak_ptr<GameObject> GetObjectPtr(GameObject* go)= 0;
};

#endif
