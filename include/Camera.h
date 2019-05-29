#pragma once
#include"Vec2.h"

#include"GameObject.h"
#include"Component.h"

class Camera{
  private:
    GameObject* focus;
  public:
    Vec2 pos  = Vec2(0,0);
    Vec2 speed = Vec2(0,0);
  public:
    Camera();
  public:
    void Follow(GameObject* focus);
  public:
    void Unfollow();
  public:
    void Update(float dt);
  public:
    static Camera* GetInstance();

};
