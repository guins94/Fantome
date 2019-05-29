#pragma once

#include"Component.h"
#include"Vec2.h"
#include"Timer.h"

#include<vector>
#include<iostream>
#include<memory>
#include<queue>

enum ActionType {MOVE=1, SHOOT =0};

class Alien : public Component{
private:
  class Action{
    public:
      Vec2 pos = Vec2(0,0);
      ActionType type;
    public:
      Action (ActionType type, float x, float y){
        this->type = type;
        this->pos.x = x;
        this->pos.y = y;
      }
  };
  private:
    Vec2 speed = Vec2(0,0);
    int nMinions;
    int nMovements;
    int hp;
    std::queue<Action> taskQueue;
    std::vector<std::weak_ptr<GameObject>> minionArray;
    int alienCount;
    Timer* restTimer;
    GameObject* player;
  public:
    Alien(GameObject* associated, int nMinions,GameObject* player);
  public:
    ~Alien();
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
