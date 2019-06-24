#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FIRE_HEADER
#define FIRE_HEADER

class Fire : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    bool falling;
    int hp;
    Timer* restTimer;
    Sound* fireSound;
  public:
    Fire(GameObject* associated);
  public:
    ~Fire();
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
