#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHAINTAIL_HEADER
#define CHAINTAIL_HEADER

/* A simplified version of ChainHead */

class ChainTail : public Component
{
  private:
    float angleRad;
    bool playing;
    Timer* playingTimer;
    Timer* possessionTimer;

  public:
    ChainTail(GameObject* associated, float angleRad);
    ~ChainTail();

    void SetChainRotation(float arc);

    float GetAngle();

    void Update(float dt);
    void Render();
    void Start();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
