#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GRAVE_HEADER
#define GRAVE_HEADER

class Grave : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    Vec2 spawnGrave = Vec2(0,0);
    bool falling;
    int hp;
    Timer* restTimer;
    Timer* possessionTimer;
    GameObject* player;
    Sound* breakBox;
    Sound* arrastaBox;
  public:
    bool playing;
  public:
    Grave(GameObject* associated);
  public:
    ~Grave();
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
  public:
    void RespawnGrave();
};

#endif
