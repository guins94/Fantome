#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef EXIT_HEADER
#define EXIT_HEADER

class Exit : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    Vec2 colliderSize = Vec2(0,0);
    int hitTime;
    bool falling;
    int hp;
    Timer* restTimer;
    GameObject* player;
    Sound* lightSound;
  public:
    Exit(GameObject* associated);
  public:
    ~Exit();
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
