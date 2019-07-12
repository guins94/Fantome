#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GRAVE_HEADER
#define GRAVE_HEADER

class Grave : public Component
{
  private:
    enum SpriteState {STOPPED, MOVING} sprtState;
    SpriteState spriteState;

    bool falling;
    int hp;

    Vec2 speed = Vec2(0,0);
    Vec2 spawnGrave = Vec2(0,0);
    Timer* restTimer;
    Timer* possessionTimer;
    GameObject* player;
    Sound* breakBox;
    Sound* arrastaBox;
    Sprite* graveSprite;

  public:
    bool playing;

    Grave(GameObject* associated);
    ~Grave();

    void RespawnGrave();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
