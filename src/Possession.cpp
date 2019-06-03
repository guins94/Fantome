#include"Alien.h"

#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"GAME.h"
#include"StageState.h"
#include"Bullet.h"
#include"PenguinBody.h"
#include"Fantome.h"
#include"Grave.h"
#include"Possession.h"
#include"Collider.h"

#include<queue>

Possession::Possession(GameObject* associated,int direction){
  this->associated = associated;
  this->direction = direction;
  //Sprite* sprite = new Sprite(this->associated);
  //sprite->Open("assets/img/penguinface.png");
  //associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
  this->restTimer = timer;
}

Possession::~Possession(){

}

void Possession::Start(){

}

void Possession::Update(float dt){
  this->restTimer->Update(dt);
  InputManager* inputManager = InputManager::GetInstance();
  if(inputManager->KeyRelease(SDLK_a) == false){
    this->associated->box.x = this->associated->box.x + dt;
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    this->associated->box.x = this->associated->box.x - dt;
  }
  if(this->restTimer->Get() >= 300){
    GameObject* fantome = new GameObject();
    fantome->box.w = 115;
    fantome->box.h = 14;
    fantome->box.x = this->associated->box.x;
    fantome->box.y = this->associated->box.y - 141;
    Fantome* fantome_component = new Fantome(fantome);
    fantome->GameObject::AddComponent(fantome_component);
    Collider* fantome_collider = new Collider(fantome);
    Vec2 offset = Vec2(0,140);
    fantome_collider->SetOffset(offset);
    fantome->GameObject::AddComponent(fantome_collider);
    Game::getInstance()->getStageState()->AddObject(fantome);
    this->restTimer->Restart();
    this->associated->RequestDelete();
  }

}

void Possession::Render(){

}

bool Possession::Is (std::string type){
  return (type == "Fantome");
}



void Possession::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
    this->falling = false;
  }
}
