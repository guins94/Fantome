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

#include<queue>

Fantome::Fantome(GameObject* associated){
  this->associated = associated;
  this->falling = true;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/fan_img/fantasma_fantome.png");
  //std::cout << "width = "<<sprite->GetWidth() << std::endl;
  //this->associated->box.w = sprite->GetWidth();
  //this->associated->box.h = sprite->GetHeight();
  associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
}

Fantome::~Fantome(){

}

void Fantome::Start(){

}

void Fantome::Update(float dt){
  if(this->falling == true){
    this->associated->box.y = this->associated->box.y + dt;
  }

  InputManager* inputManager = InputManager::GetInstance();
  if(inputManager->KeyRelease(SDLK_a) == false){
    this->associated->box.x = this->associated->box.x - dt;
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    this->associated->box.x = this->associated->box.x + dt;
  }
}

void Fantome::Render(){

}

bool Fantome::Is (std::string type){
  if(type == "Fantome"){
    return true;
  }
  else
    return false;
}



void Fantome::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
    std::cout << "colliding with ground" << std::endl;
    this->falling = false;
  }
  if(other.GetComponent("Tile") != nullptr){
    std::cout << "colliding with ground" << std::endl;
    this->falling = false;
  }
  //if(other.GetComponent("Bullet") != nullptr){
    //Bullet* bullet = (Bullet*)other.GetComponent("Bullet");
    //if(bullet->targetsPlayer == true){
      //this->hp = this->hp - 10;
    //}
  //}
}
