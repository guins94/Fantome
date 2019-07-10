#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TITLESTATE_HEADER
#define TITLESTATE_HEADER

class TitleState: public State
{
  private:
    bool started, willExit;

    enum SpriteState {PLAY, EXIT} sprtState;
    SpriteState spriteState;

    GameObject* titleGo;
    Music backgroundMusic;
    Sprite* playOrExit;
    Sprite* fantomeGlow;
    Sprite* fadeOut;
    Timer optionTimer, exitTimer;

    std::vector<std::shared_ptr<GameObject>> objectArray;

  public:
    TitleState();
    ~TitleState();

    void PlayExitAnimation();

    void LoadAssets();

    void Start();
    void Update();
    void Render();
    void Pause();
    void Resume();
    std::weak_ptr<GameObject> AddObject(GameObject* go);
    std::weak_ptr<GameObject> GetObjectPtr(GameObject* go);
};

#endif
