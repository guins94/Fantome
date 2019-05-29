#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"

class Timer{
  private:
    float time;
  public:
    Timer();
  public:
    void Update(float dt);
  public:
    void Restart();
  public:
    float Get();
};
