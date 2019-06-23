#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FANTOME_HEADER
#define FANTOME_HEADER

class Fantome : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    float fallingSpeed = 0;
    int nMovements;
    int hp;
    Timer* restTimer;
    GameObject* player;
  public:
    Fantome(GameObject* associated);
  public:
    ~Fantome();
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

};

#endif
