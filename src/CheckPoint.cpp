#include"CheckPoint.h"

CheckPoint::CheckPoint(GameObject* associated,int checkID){
  this->associated = associated;
  this->checkID = checkID;
  //Sprite* sprite = new Sprite(this->associated);
  //sprite->Open("assets/img/penguinface.png");
  //associated->GameObject::AddComponent(sprite);
  Sound* sound = new Sound(this->associated,"assets/SFX/fire.ogg");
  //sound->Play(1);
  this->fireSound = sound;
  Timer* timer = new Timer();
  this->restTimer = timer;
}

CheckPoint::~CheckPoint(){

}

void CheckPoint::Start(){

}

void CheckPoint::Update(float dt){
  /*this->restTimer->Update(dt);

  if(this->restTimer->Get() >= 1){

  }*/
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fantomeState->isAlive == false && this->checkID == fantomeState->checkID){
    GameObject* possession = new GameObject();
    possession->box.w = 30;
    possession->box.h = 30;
    possession->box.x = this->associated->box.x;//respawnPosition.x;
    possession->box.y = this->associated->box.y;//respawnPosition.y;
    possession->GameObject::AddComponent(new Possession(possession,2));
    Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
    possession->GameObject::AddComponent(possession_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(possession);
    fantomeState->isAlive = true;
    //game->GetCurrentState()->AddObject(minion_go)
  }

}

void CheckPoint::Render(){

}

bool CheckPoint::Is (std::string type){
  return (type == "Fantome");
}



void CheckPoint::NotifyCollision(GameObject& other){

  if(other.GetComponent("Fantome") != nullptr){
    FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
    //this->respawnPosition.x = fantomeState->PlayerPosition.x;
    //this->respawnPosition.y = fantomeState->PlayerPosition.y;
    fantomeState->checkID = this->checkID;
  }
}
