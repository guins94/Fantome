#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef INITIALSTONE_HEADER
#define INITIALSTONE_HEADER

class InitialStone : public Component{
  private:
    int hitTime;
    bool createFantome = true;
    int hp;
    Timer* restTimer;
    GameObject* player;
    Sound* lightSound;
  public:
    InitialStone(GameObject* associated);
  public:
    ~InitialStone();
  public:
    void Start();
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is (std::string type);
  public:
    void NotifyCollision(GameObject& other);

};

#endif
