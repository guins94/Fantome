#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef DEATHGHOST_HEADER
#define DEATHGHOST_HEADER

class DeathGhost : public Component
{
  private:
    int hp;

    Vec2 spawnGhost;
    //Sound blade;
    Timer restTimer;

    Sprite* deathGhostSprite;

  public:
    enum SpriteState {STANDING, FOLLOWING, ATTACKING} sprtState;
    SpriteState spriteState;

    bool isFantomeInSight;

    DeathGhost(GameObject* associated, int direction);
    ~DeathGhost();

    bool IsFantomeRight();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
    void GhostAttack();
};

#endif
