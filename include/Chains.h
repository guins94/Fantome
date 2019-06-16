#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHAINS_HEADER
#define CHAINS_HEADER

class Chains : public Component{
  private:
    int hp;
    Timer* restTimer;
    Timer* possessionTimer;
    int nLinks;
    Chains* rightChain;
    Chains* leftChain;
    Chains* dest;
    GameObject* destgo;
  public:
    bool playing;
  public:
    Chains(GameObject* associated);
    Chains(GameObject* associated, int nLinks);
  public:
    ~Chains();
  public:
    void LinkChains(Chains* dest,GameObject* destgo);
  public:
    void Start();
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is (std::string type);
  public:
    void NotifyCollision(GameObject& other);
};

#endif
