#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"

class PenguinBody: public Component{
  private:
    std::weak_ptr< GameObject > pcannon;
    Vec2 speed = Vec2(0,0);
    float linearSpeed;
    float angle;
    int hp;

  public:
    GameObject* player;
  public:
    PenguinBody(GameObject* associated);
  public:
    ~PenguinBody();
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    void Start();
  public:
    void NotifyCollision(GameObject& other);
};
