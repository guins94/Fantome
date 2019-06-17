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
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  fantomeState->fantomeExist = true;

  Rect auxBox = this->associated->futureBox;

  /* Calculando eixo y da futura posição do Fantome */
  this->associated->futureBox.y = this->associated->futureBox.y + dt * GameData::fantomeSpeed.y;
  if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
    this->associated->box.y = this->associated->futureBox.y;
  this->associated->futureBox = auxBox;

  /* Calculando eixo x da futura posição do Fantome */

  if(this->playing == true){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_a)){
      this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;
    }
    if(!inputManager->KeyRelease(SDLK_d)){
      this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;
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
  this->associated->futureBox = this->associated->box;
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
