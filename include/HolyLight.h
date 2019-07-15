#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef HOLYLIGHT_HEADER
#define HOLYLIGHT_HEADER

class HolyLight : public Component
{
  private:
    Timer soundCooldownTimer;
    GameObject* player;
    Sound* lightSound;

    bool isSFXEnabled;

  public:
    HolyLight(GameObject* associated, bool isSFXEnabled);
    ~HolyLight();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
