#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef DEATHSIGHT_HEADER
#define DEATHSIGHT_HEADER

class DeathGhostSight : public Component
{
  private:
    GameObject* deathGhost;

  public:
    DeathGhostSight(GameObject* associated, GameObject* deathGhost, float deathGhostWidth, float deathGhostHeight);
    ~DeathGhostSight();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
