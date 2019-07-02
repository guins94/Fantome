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
    Timer* playingTimer;
    Timer* possessionTimer;

  public:
    bool playing;
    ChainHead* chainHead;   // Pointer to Store From Which ChainHead This ChainTail Belongs To

    ChainTail(GameObject* associated, GameObject* chainHead, float angleRad);
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
