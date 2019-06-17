#include"HolyLight.h"

HolyLight::HolyLight(GameObject* associated,int weigth,int height,float hitTime){
  this->associated = associated;
  this->colliderSize = Vec2(weigth,height);
  this->hitTime == hitTime;
  Timer* timer = new Timer();
  this->restTimer = timer;
}

HolyLight::~HolyLight(){

}

void HolyLight::Start(){

}

void HolyLight::Update(float dt){
  this->restTimer->Update(dt);
  /*if(this->hitTime == -1){

  }else{

  }*/
  if(this->restTimer->Get() <= this->hitTime){
    this->associated->RequestDelete();
  }


}

void HolyLight::Render(){

}

bool HolyLight::Is (std::string type){
  return (type == "HolyLight");
}



void HolyLight::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
    this->falling = false;
  }
}
