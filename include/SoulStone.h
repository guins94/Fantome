#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FIRE_HEADER
#define FIRE_HEADER

class SoulStone : public Component
{
  private:
    float distanceFromFantome;
    Sound* nearbySound;
    Timer soundTimer;

  public:
    SoulStone(GameObject* associated);
    ~SoulStone();

    void Start();
    void Update(float dt);
    void Render();
    bool Is (std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
