#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"GAME.h"
#include"StageState.h"
#include"Bullet.h"
#include"PenguinBody.h"
#include"Grave.h"
#include"Fantome.h"
#include"Collider.h"

#include<queue>

Grave::Grave(GameObject* associated){
  this->associated = associated;
  this->falling = true;
  this->playing = false;
  Timer* timer = new Timer();
}

Grave::~Grave(){

}

void Grave::Start(){

}

void Grave::Update(float dt){
  if(this->falling == true){
    this->associated->box.y = this->associated->box.y + dt;
  }

  this->falling = false;
  if(this->playing == true){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_a) == false){
      this->associated->box.x = this->associated->box.x - dt;
    }
    if(inputManager->KeyRelease(SDLK_d) == false){
      this->associated->box.x = this->associated->box.x + dt;
    }

    if((inputManager->KeyRelease(SDLK_SPACE) == false) && (inputManager->KeyRelease(SDLK_w) == false)){
      GameObject* fantome = new GameObject();
      fantome->box.w = 115;
      fantome->box.h = 140;
      fantome->box.x = this->associated->box.x;
      fantome->box.y = this->associated->box.y - 141;
      Fantome* fantome_component = new Fantome(fantome);
      fantome->GameObject::AddComponent(fantome_component);
      Collider* fantome_collider = new Collider(fantome);
      fantome->GameObject::AddComponent(fantome_collider);
      Game::getInstance()->getStageState()->AddObject(fantome);
      //game->getStageState()->AddObject(minion_go)
      this->playing = false;
    }

  }
}

void Grave::Render(){

}

bool Grave::Is (std::string type){
  return ("Grave" == type);
}

void Grave::NotifyCollision(GameObject& other){
	if(other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->playing = true;
    }
  }
}
