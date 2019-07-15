#include"InitialStone.h"

InitialStone::InitialStone(GameObject* associated){
  this->associated = associated;
  //this->colliderSize = Vec2(weigth,height);
  //this->hitTime == hitTime;
  Timer* timer = new Timer();
  this->restTimer = timer;
  //Sound* sound = new Sound(this->associated,"assets/SFX/light.ogg");
  //this->lightSound = sound;
}

InitialStone::~InitialStone(){

}

void InitialStone::Start(){

}

void InitialStone::Update(float dt){
  //this->restTimer->Update(dt);
  //this->restTimer->Get()
  //this->lightSound->Play(1);
  //this->restTimer->Restart();
  this->restTimer->Update(dt);
  if(this->restTimer->Get() >= 2 && createFantome == true){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
      GameObject* possession = new GameObject();
      possession->box.w = 30;
      possession->box.h = 30;
      possession->box.x = this->associated->box.x + 200;//respawnPosition.x;
      possession->box.y = this->associated->box.y;//respawnPosition.y;
      possession->GameObject::AddComponent(new Possession(possession,2));
      //Collider* possession_collider = new Collider(possession);
      //possession->GameObject::AddComponent(possession_collider);
      //Game::GetInstance()->GetCurrentState()->AddObject(possession);
      fantomeState->isAlive = true;
      fantomeState->teleportID = 0;
      createFantome = false;
      this->restTimer->Restart();

    }

  }

}

void InitialStone::Render(){

}

bool InitialStone::Is (std::string type){
  return (type == "InitialStone");
}



void InitialStone::NotifyCollision(GameObject& other){

}
