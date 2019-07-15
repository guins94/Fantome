#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef FANTOME_HEADER
#define FANTOME_HEADER

class Fantome : public Component
{
  private:
    enum SpriteState {STANDING, RIGHT, LEFT, FALLING} sprtState;
    SpriteState spriteState;

    int hp;
    float fallingSpeed;
    Timer* restTimer;
    Timer resetTimer;
    GameObject* player;

  public:
    Fantome(GameObject* associated);
    ~Fantome();

    void Reset();
    void KillFantome();
    void Possess();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
