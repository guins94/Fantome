#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef COLLIDER_HEADER
#define COLLIDER_HEADER

class Collider : public Component
{
  private:
    Vec2 scale;
    Vec2 offset;

  public:
    Rect box;
    float angleDeg;

    Collider(GameObject* associated, Vec2 scale, Vec2 offset);

    void SetScale(Vec2 scale);
    void SetOffset(Vec2 offset);

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision();
};

#endif
