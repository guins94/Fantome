#include "Chains.h"

Chains::Chains(GameObject* associated, int nLinks){
  this->associated = associated;
  this->nLinks = nLinks;
  this->playing = false;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->possessionTimer = new Timer();

  this->dest = nullptr;
  rightChain = nullptr;
  leftChain = nullptr;

  Sprite* chainssprite = new Sprite(this->associated);
  chainssprite->Open("assets/img/minionbullet1.png");
  this->associated->GameObject::AddComponent(chainssprite);
}

void Chains::LinkChains(Chains* dest,GameObject* destgo){
  this->destgo = destgo;
}


Chains::~Chains(){

}

void Chains::Start(){

}

void Chains::Update(float dt){


  InputManager* inputManager = InputManager::GetInstance();
  this->possessionTimer->Update(dt);

  if(this->playing == true){

    if(this->possessionTimer->Get() >= 1 && (inputManager->KeyRelease(SDLK_SPACE) == false) && (inputManager->KeyRelease(SDLK_w) == false)){
      Camera::Follow(nullptr);
        GameObject* possession = new GameObject();
        possession->box.w = 30;
        possession->box.h = 30;
        possession->box.x = this->associated->box.x;
        possession->box.y = this->associated->box.y;
        possession->GameObject::AddComponent(new Possession(possession,2));
        Collider* possession_collider = new Collider(possession);
        possession->GameObject::AddComponent(possession_collider);
        Game::GetInstance()->GetCurrentState()->AddObject(possession);
        //game->GetCurrentState()->AddObject(minion_go)
        this->playing = false;
        this->possessionTimer->Restart();
      }
    }
}

void Chains::Render(){

}

//void Chains::setPlaying(bool playing){
//  this->playing = playing;
//}

bool Chains::Is (std::string type){
  return ("Chains" == type);
}

void Chains::NotifyCollision(GameObject& other){
	if(this->possessionTimer->Get() >= 1 && other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->playing = true;
    }
  }
}
