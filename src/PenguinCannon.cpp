#include"Minion.h"
#include"Vec2.h"
#include"GameObject.h"
#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"Bullet.h"
#include"GAME.h"
#include"PenguinCannon.h"
#include"Collider.h"

#include<queue>

#include<string>

PenguinCannon::PenguinCannon(GameObject* associated,std::weak_ptr< GameObject > penguinBody ){
  this->associated = associated;
  this->pbody = penguinBody;
  this->angle = 0;
  Sprite* PenguinCannon_sprite = new Sprite(this->associated);
  PenguinCannon_sprite->Open("assets/img/cubngun.png");
  this->associated->GameObject::AddComponent(PenguinCannon_sprite);
}

void PenguinCannon::Update(float dt){
  GameObject* penguinBody = pbody.lock().get();
  this->associated->box.x = penguinBody->box.x;
  this->associated->box.y = penguinBody->box.y;


  InputManager* inputManager = InputManager::GetInstance();
  int x = this->associated->box.x;
  int y = this->associated->box.y;
  float distx = x - inputManager->GetMouseX();
  float disty = -(-y + inputManager->GetMouseY());
  float angle = atan(disty/distx);
  if(distx>=0){
    this->associated->angleDeg = angle*180/3.14 - 180;
  }else{
    this->associated->angleDeg = angle*180/3.14;
  }

  if(inputManager->MousePress(SDL_BUTTON_LEFT) == true){
    Shoot(angle , distx);
  }

}


void PenguinCannon::Render(){

}


bool PenguinCannon::Is(std::string type){
  return (type == "PenguinCannon");
}


void PenguinCannon::Shoot(float angle,float distx){
  Game* game = Game::getInstance();
  State* StageState = game->getStageState();

  GameObject* bullet_go = new GameObject();
  bullet_go->box.x = this->associated->box.x;
  bullet_go->box.y = this->associated->box.y;
  bullet_go->box.w = 30;
  bullet_go->box.h = 30;
  int speed;
  if(distx<=0){
    speed = 15;
    bullet_go->angleDeg = angle*180/3.14;
  }
  else{
    speed = -15;
    bullet_go->angleDeg = angle*180/3.14 + 180;
  }
  Bullet* bullet = new Bullet(bullet_go, -angle, speed, 10, 500,"assets/img/penguinbullet.png");
  bullet_go->GameObject::AddComponent(bullet);
  Collider* bullet_collider = new Collider(bullet_go);
  bullet_go->GameObject::AddComponent(bullet_collider);
  StageState->AddObject(bullet_go);
}
