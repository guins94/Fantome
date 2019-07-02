#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHAIN_HEADER
#define CHAIN_HEADER

class Chain : public Component
{
  private:
    ChainHead* chainHead;         // Pointer to Store From Which ChainHead This Chain Belongs To
    int chainCode;                // Chain ID
    bool wasCurrentChainModified; // Flag That Limits The Number Of Times The Chain Can Modify Current Chain Value

  public:
    Timer* travelCooldown;  // Timer To Limit Travel Between Chains
    bool isPlaying;         // Flag That Shows Wether The Chain Is Being Controlled Or Not

    Chain(GameObject* associated, GameObject* chainHead, int chainCode);
    ~Chain();

    int GetChainCode();

    void Update(float dt);
    void Render();
    void Start();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
