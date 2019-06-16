#include "Ground.h"

Ground::Ground(GameObject* associated){
  this->associated = associated;
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
