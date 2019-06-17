#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GROUND_HEADER
#define GROUND_HEADER

class Ground : public Component
{
  private:
    TileMap* tileMap;
    Collider* collider;

  public:
    Ground(GameObject* associated);

    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void Start();
    void NotifyCollision(GameObject& other);
};

#endif
