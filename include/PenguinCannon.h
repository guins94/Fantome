#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"

class PenguinCannon : public Component{
  private:
    std::weak_ptr< GameObject > pbody;
    float angle;
  public:
    PenguinCannon(GameObject* associated,std::weak_ptr< GameObject > penguinBody );
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void Shoot(float angle,float distx);
};
