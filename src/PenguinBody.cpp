#include"Minion.h"
#include"Vec2.h"
#include"GameObject.h"
#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"Bullet.h"
#include"GAME.h"
#include"PenguinBody.h"
#include"PenguinCannon.h"
#include"StageState.h"

#include<queue>

#include<string>

PenguinBody::PenguinBody(GameObject* associated){
  this->associated = associated;
  Vec2 speed = Vec2(0,0);
  this->linearSpeed = 0;
  this->angle = 0;
  this->hp = 20;
  Sprite* PenguinBody_sprite = new Sprite(this->associated);
  PenguinBody_sprite->Open("assets/img/penguin.png");
  this->associated->GameObject::AddComponent(PenguinBody_sprite);
  this->player = this->associated;
}

PenguinBody::~PenguinBody(){

}

void PenguinBody::Update(float dt){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_a) == false){
      this->associated->box.x = this->associated->box.x - dt;
    }
    if(inputManager->KeyRelease(SDLK_d) == false){
      this->associated->box.x = this->associated->box.x + dt;
    }
    if(inputManager->KeyRelease(SDLK_w) == false){
      this->associated->box.y = this->associated->box.y - dt;
    }
    if(inputManager->KeyRelease(SDLK_s) == false){
      this->associated->box.y = this->associated->box.y + dt;
    }
    this->player = this->associated;

    if(this->hp <= 0){
      Game* game = Game::getInstance();
      GameObject* boom = new GameObject();
      boom->box.x = this->associated->box.x;
      boom->box.y = this->associated->box.y;
      Sprite* sprite_boom = new Sprite(boom,5,30);//new Minion(minion_go, game->getStageState()->GetObjectPtr(this->associated),angle_minion*(i-1));
      sprite_boom->Open("assets/img/penguindeath.png");
      sprite_boom->secondsToSelfDestruct = 100;
      boom->GameObject::AddComponent(sprite_boom);
      game->getStageState()->AddObject(boom);
      this->hp = 10;
      //this->associated->RequestDelete();
    }
}

void PenguinBody::Render(){

}

bool PenguinBody::Is(std::string type){
  if(type == "PenguinBody"){
    return true;
  }
  else
    return false;
}

void PenguinBody::Start(){
  Game* game = Game::getInstance();
  GameObject* PenguinCannon_go = new GameObject();
  PenguinCannon_go->box.x = this->associated->box.x;
  PenguinCannon_go->box.y = this->associated->box.y;
  PenguinCannon* penguinCannon = new PenguinCannon(PenguinCannon_go, game->getStageState()->GetObjectPtr(this->associated));
  PenguinCannon_go->GameObject::AddComponent(penguinCannon);
  game->getStageState()->AddObject(PenguinCannon_go);
}

void PenguinBody::NotifyCollision(GameObject& other){
  //if(other.GetComponent("Bullet") != nullptr){
    //std::cout << "bullet hit penguim " << std::endl;
//  }
  if(other.GetComponent("Bullet") != nullptr){
    Bullet* bullet = (Bullet*)other.GetComponent("Bullet");
    if(bullet->targetsPlayer == false){
      this->hp = this->hp - 10;
    }
  }
}
