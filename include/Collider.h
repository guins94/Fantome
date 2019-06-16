#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef COLLIDER_HEADER
#define COLLIDER_HEADER

class Collider : public Component{
  private:
    Vec2 scale = Vec2(0,0);
    Vec2 offset = Vec2(0,0);
  public:
    Rect box;
    float angleDeg;
  public:
    Collider(GameObject* associated, Vec2 scale = Vec2(1,1), Vec2 offset = Vec2(0,0));
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void SetScale(Vec2 scale);
  public:
    void SetOffset(Vec2 offset);
};

#endif
