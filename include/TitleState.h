#pragma once

#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"
#include"State.h"

class TitleState: public State{
private:
  Music* music;
  Sprite* bg;
  bool started;
  std::vector< std::shared_ptr<GameObject>> objectArray;
private:
  void StartArray();
  void UpdateArray(float dt);
  void RenderArray();
  void Input();
public:
  TitleState();
public:
  ~TitleState();
public:
  bool QuitRequested();
public:
  void LoadAssets();
public:
  void Update();
public:
  void Render();
public:
  void Start();
public:
  void AddObject(int mouseX,int mouseY);
public:
  std::weak_ptr< GameObject > AddObject(GameObject* go);
public:
  std::weak_ptr< GameObject > GetObjectPtr(GameObject* go);
public:
  bool PopRequested();
public:
  void Pause ();
public:
  void Resume ();
};
