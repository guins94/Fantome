#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHAINHEAD_HEADER
#define CHAINHEAD_HEADER

class ChainHead : public Component
{
  private:
    int nChains;
    float angleRad, chainWidth, chainHeight;
    bool playing;
    Vec2 lastChainPosition;
    Timer* playingTimer;
    Timer* possessionTimer;
    Timer* travelCooldown;

  public:
    int currentChain;
    std::vector<std::weak_ptr<GameObject>> chainArray;

    ChainHead(GameObject* associated, int nChains, float angleRad);
    ~ChainHead();

    void SetChainNumber(int nChains);
    void SetChainRotation(float arc);

    float GetChainWidth();
    float GetChainHeight();
    float GetAngle();

    float GetPlayingTimer();

    Vec2 GetLastChainPosition();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
