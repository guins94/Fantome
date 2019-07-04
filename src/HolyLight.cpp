#include"HolyLight.h"

HolyLight::HolyLight(GameObject* associated,int weigth,int height,int hitTime){
  this->associated = associated;
  this->colliderSize = Vec2(weigth,height);
  this->hitTime == hitTime;
  Timer* timer = new Timer();
  this->restTimer = timer;
  Sound* sound = new Sound(this->associated,"assets/SFX/light.ogg");
  this->lightSound = sound;
}

HolyLight::~HolyLight(){

}

void HolyLight::Start(){

}

void HolyLight::Update(float dt){
  this->restTimer->Update(dt);
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fabs(distanceFantome) <= 300 && fantomeState->fantomeExist == true){
    if(this->restTimer->Get() >= 6){
      this->lightSound->Play(1);
      this->restTimer->Restart();
    }
  }


}

void HolyLight::Render(){

}

bool HolyLight::Is (std::string type){
  return (type == "HolyLight");
}



void HolyLight::NotifyCollision(GameObject& other){

}
