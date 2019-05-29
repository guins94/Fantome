#pragma once

#include<iostream>
#include<vector>
#include<string>

#include"Rect.h"
#include"Component.h"
#include"Vec2.h"

class Bullet : public Component{
  private:
    Vec2 speed = Vec2(0,0);
    float distanceLeft;
    int damage;
  public:
    bool targetsPlayer;
  public:
      Bullet(GameObject* associated, float angle, float speed, int damage, float maxDistance, std::string sprite);
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    bool Is(std::string type);
  public:
    int GetDamage();
  public:
    void Start();
  public:
    void NotifyCollision(GameObject& other);
};
