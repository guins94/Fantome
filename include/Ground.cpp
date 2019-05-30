#include"Ground.h"

#include<queue>

#include<string>

Ground::Ground(GameObject* associated){
  this->associated = associated;
  Sprite* sprite = new Sprite(associated);
  sprite->Open("assets/img/minion.png");
  this->associated->GameObject::AddComponent(sprite);
}

void Ground::Update(float dt){

}

void Ground::Render(){

}

bool Ground::Is(std::string type){
  if(type == "Ground"){
    return true;
  }
  else
    return false;
}


void Ground::Start(){

}

void Ground::NotifyCollision(GameObject& other){

}
