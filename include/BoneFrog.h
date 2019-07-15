#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef BONEFROG_HEADER
#define BONEFROG_HEADER

class BoneFrog : public Component
{
  private:
    int hp;
    bool isGoingRight, isWild;
    float fallingSpeed, distanceWalked;

    enum SpriteState {STANDING, WALKING, JUMPING, FALLING, DEAD} sprtState;
    SpriteState spriteState;

    Sprite* boneFrogSprite;
    Timer restTimer;
    Timer possessionTimer;
    Sound* frogJump;
    Sound* frogLand;

  public:
    bool isPlaying;

    BoneFrog(GameObject* associated, bool isWild);

    void FlipWildBoneFrog();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};
#endif
