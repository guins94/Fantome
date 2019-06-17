#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef BONEPILE_HEADER
#define BONEPILE_HEADER

enum BoneState {MOVELEFT=1, MOVERIGHT =0, STOP = 2};

class BonePile : public Component{
  private:
    Vec2 spawnBone = Vec2(0,0);
    int walkLimitRigth;
    int walkLimitLeft;
    bool falling;
    int direction;
    int hp;
    Timer* restTimer;
  public:
    BonePile(GameObject* associated, int walkLimit);
  public:
    ~BonePile();
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
