#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef CHAIN_HEADER
#define CHAIN_HEADER

class Chain : public Component
{
  private:
    GameObject* chainHead;

  public:
    Chain(GameObject* associated);
    ~Chain();

    void Update(float dt);
    void Render();
    void Start();
    bool Is(std::string type);
    void NotifyCollision(GameObject& other);
};

#endif
