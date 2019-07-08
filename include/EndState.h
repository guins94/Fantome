#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef ENDSTATE_HEADER
#define ENDSTATE_HEADER

class EndState: public State
{
  private:
    bool started;
    Music backgroundMusic;
    std::vector< std::shared_ptr<GameObject>> objectArray;

  public:
    EndState();
    ~EndState();

    bool QuitRequested();
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
