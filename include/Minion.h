#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"

class Minion : public Component{
  private:
    GameObject* alienCenter;
    float arc;
  public:
    Minion(GameObject* associated, std::weak_ptr< GameObject> alienCenter, float arcOffsetDeg = 0);
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void Shoot(Vec2 target);
  public:
    void Start();
};
