#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"

#include <cmath>

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
  public:
    static inline bool IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB);
};
