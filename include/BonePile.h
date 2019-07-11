#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef BONEPILE_HEADER
#define BONEPILE_HEADER

enum BoneState {MOVELEFT=1, MOVERIGHT =0, STOP = 2};

class BonePile : public Component
{
  private:
    Vec2 spawnBone = Vec2(0,0);
    int walkLimitRigth;
    int walkLimitLeft;
    bool falling;
    int direction;
    int hp;
    Timer* restTimer;
    Sound* frogJump;

  public:
    BonePile(GameObject* associated, int walkLimit);
    ~BonePile();

    void Start();
    void Update(float dt);
    void Render();
    bool Is (std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
