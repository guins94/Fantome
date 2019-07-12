#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TELEPORTATIONORB_HEADER
#define TELEPORTATIONORB_HEADER



class TeleportationOrb : public Component
{
  private:
    bool falling;
    Timer* yellowTimer;
    Timer* restTimer;
    Sound* fireSound;
    int teleportID;
    Vec2 leftOrbPosition;
    Vec2 rightOrbPosition;
    bool switchPlaces = true;
    Sprite* boneFrogSprite;

  public:
    TeleportationOrb(GameObject* associated, int checkID);
    ~TeleportationOrb();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);

};

#endif
