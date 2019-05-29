#pragma once

#include"Component.h"
#include"Vec2.h"
#include"Timer.h"

#include<vector>
#include<iostream>
#include<memory>
#include<queue>

class Fantome : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    bool falling;
    int nMinions;
    int nMovements;
    int hp;
    Timer* restTimer;
    GameObject* player;
  public:
    Fantome(GameObject* associated);
  public:
    ~Fantome();
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
