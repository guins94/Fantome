#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef DEATHGHOST_HEADER
#define DEATHGHOST_HEADER

class DeathGhost : public Component{
  private:
    Vec2 spawnGhost = Vec2(0,0);
    Sound* blade;
    bool falling;
    int hp;
    Timer* restTimer;
  public:
    DeathGhost(GameObject* associated, int direction);
  public:
    ~DeathGhost();
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
    void GhostAttack();
};

#endif
