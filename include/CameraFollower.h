#pragma once

#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include"GameObject.h"

class CameraFollower : public Component{
  public:
    CameraFollower(GameObject* go);
  public:
    void Update(float dt);
  public:
    void Render();
  public:
    void Start();
  public:
    bool Is(std::string type);
};
