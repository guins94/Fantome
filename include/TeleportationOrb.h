#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TELEPORTATIONORB_HEADER
#define TELEPORTATIONORB_HEADER



class TeleportationOrb : public Component{
  private:
    bool falling;
    Timer* yellowTimer;
    Timer* restTimer;
    Sound* fireSound;
    int teleportID;
    Vec2 leftOrbPosition;
    Vec2 rightOrbPosition;
    bool switchPlaces = true;
  public:
    TeleportationOrb(GameObject* associated, int checkID);
  public:
    ~TeleportationOrb();
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
