#include "BoneFrog.h"

BoneFrog::BoneFrog(GameObject* associated){
  this->associated = associated;
  this->falling = false;
  this->playing = false;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->possessionTimer = new Timer();
  this->fallingSpeed = 0;
  this->gravity = 5;
}

void BoneFrog::Update(float dt){
  this->possessionTimer->Update(dt);
  InputManager* inputManager = InputManager::GetInstance();

  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  Rect auxBox = this->associated->futureBox;

  /* Calculando eixo y da futura posição do Fantome */

  if(this->falling == true){
    this->associated->futureBox.y = this->associated->futureBox.y + dt * this->fallingSpeed;
    this->fallingSpeed = this->fallingSpeed + this->gravity;
  }
  if(!fantomeState->WillCollideWithGround(this->associated->futureBox)){
      this->associated->box.y = this->associated->futureBox.y;
  }
  this->associated->futureBox = auxBox;

  if(this->playing == true){

    /* Calculando eixo x da futura posição do Fantome */
    if(!inputManager->KeyRelease(SDLK_a)){
      this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox)){
        this->associated->box.x = this->associated->futureBox.x;
      }
      this->associated->futureBox = auxBox;
    }
    if(!inputManager->KeyRelease(SDLK_d)){
      this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;
    }

    this->associated->futureBox = this->associated->box;

      if(inputManager->KeyRelease(SDLK_w) == false){
        this->restTimer->Update(dt);
        //if(this->restTimer->Get() >= 45){
        this->falling = true;
        this->fallingSpeed = -300;
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

void BoneFrog::Render(){

}

bool BoneFrog::Is(std::string type){
  return ("BoneFrog" == type);
}

void BoneFrog::NotifyCollision(GameObject& other){
	if(this->possessionTimer->Get() >= 1 && other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->playing = true;
      Camera::Follow(this->associated);
    }
  }
}

void BoneFrog::Start(){

}
