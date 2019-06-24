#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef BONEFROG_HEADER
#define BONEFROG_HEADER


class BoneFrog : public Component{
  private:
    bool falling;
    int hp;
    Timer* restTimer;
    Timer* possessionTimer;
    float fallingSpeed;
    float gravity;
    Sound* frogJump;
    Sound* frogLand;
  public:
    bool playing;
  public:
    BoneFrog(GameObject* associated);
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void NotifyCollision(GameObject& other);
  public:
    void Start();
};
#endif
