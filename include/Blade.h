#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef BLADE_HEADER
#define BLADE_HEADER

class Blade : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    Vec2 colliderSize = Vec2(0,0);
    int hitTime;
    bool falling;
    int hp;
    Timer* restTimer;
    GameObject* player;
  public:
    Blade(GameObject* associated,int weigth,int height,int hitTime);
  public:
    ~Blade();
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
