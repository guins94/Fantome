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
    Timer* restTimer;
    Timer* possessionTimer;
    float fallingSpeed;
    Sound* frogJump;
    Sound* frogLand;

  public:
    bool isPlaying;

    BoneFrog(GameObject* associated);

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};
#endif
