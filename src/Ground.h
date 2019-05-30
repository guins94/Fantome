#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"
#include"Camera.h"
#include"Sprite.h"
#include"Bullet.h"
#include"GAME.h"
#include"Collider.h"

class Ground : public Component{
  private:

  public:
    Ground(GameObject* associated);
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
