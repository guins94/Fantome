#include "Grave.h"

Grave::Grave(GameObject* associated){
  this->associated = associated;
  this->falling = true;
  this->playing = false;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->possessionTimer = new Timer();
}

Grave::~Grave(){

}

void Grave::Start(){

}

void Grave::Update(float dt){
  this->possessionTimer->Update(dt);
  //if(this->falling == true){
    //this->associated->box.y = this->associated->box.y + dt;
  //}

  //this->falling = false;
  if(this->playing == true){

    InputManager* inputManager = InputManager::GetInstance();

      if(inputManager->KeyRelease(SDLK_a) == false){
        this->restTimer->Update(dt);
        //if(this->restTimer->Get() >= 45){
          this->associated->box.x = this->associated->box.x - dt* GameData::fantomeSpeed.x;
          this->restTimer->Restart();
        //}
      }
      if(inputManager->KeyRelease(SDLK_d) == false){
        this->restTimer->Update(dt);
        //if(this->restTimer->Get() >= 45){
        this->associated->box.x = this->associated->box.x + dt* GameData::fantomeSpeed.x;
        this->restTimer->Restart();
        //}
      }
    if(this->possessionTimer->Get() >= 1 && (inputManager->KeyRelease(SDLK_SPACE) == false) && (inputManager->KeyRelease(SDLK_w) == false)){

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

void Grave::Render(){

}

bool Grave::Is (std::string type){
  return ("Grave" == type);
}

void Grave::NotifyCollision(GameObject& other){
	if(this->possessionTimer->Get() >= 1 && other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->playing = true;
      Camera::Follow(this->associated);
    }
  }
}
