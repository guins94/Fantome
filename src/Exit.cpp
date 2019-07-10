#include"Exit.h"

Exit::Exit(GameObject* associated){
  this->associated = associated;
  //this->colliderSize = Vec2(weigth,height);
  //this->hitTime == hitTime;
  Timer* timer = new Timer();
  this->restTimer = timer;
  Sound* sound = new Sound(this->associated,"assets/SFX/light.ogg");
  this->lightSound = sound;
}

Exit::~Exit(){

}

void Exit::Start(){

}

void Exit::Update(float dt){
  //this->restTimer->Update(dt);
  //this->restTimer->Get()
  //this->lightSound->Play(1);
  //this->restTimer->Restart();

}

void Exit::Render(){

}

bool Exit::Is (std::string type){
  return (type == "Exit");
}



void Exit::NotifyCollision(GameObject& other){

}
