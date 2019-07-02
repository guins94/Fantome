#include"Blade.h"

Blade::Blade(GameObject* associated,int weigth,int height,int hitTime){
  this->associated = associated;
  this->colliderSize = Vec2(weigth,height);
  this->hitTime == hitTime;
  Timer* timer = new Timer();
  this->restTimer = timer;
}

Blade::~Blade(){

}

void Blade::Start(){

}

void Blade::Update(float dt){
  this->restTimer->Update(dt);

  if(this->restTimer->Get() >= 1){
    this->associated->RequestDelete();
  }


}

void Blade::Render(){

}

bool Blade::Is (std::string type){
  return (type == "Blade");
}



void Blade::NotifyCollision(GameObject& other){

}
