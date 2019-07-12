#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHECKPOINT_HEADER
#define CHECKPOINT_HEADER

class CheckPoint : public Component
{
  private:
    enum SpriteState {DEACTIVATED, ACTIVATED} sprtState;
    SpriteState spriteState;

    int checkPointID;

    bool willActivate;

    Vec2 speed;
    Vec2 respawnPosition = Vec2(300, 290);
    Timer restTimer;
    GameObject* player;
    Sound* fireSound;
    Sprite* checkPointSprite;

  public:
    CheckPoint(GameObject* associated, int checkID);
    ~CheckPoint();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
