#include"Minion.h"
#include"Vec2.h"
#include"GameObject.h"
#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"Bullet.h"
#include"GAME.h"
#include"Collider.h"

#include<queue>

#include<string>

Minion::Minion(GameObject* associated,std::weak_ptr< GameObject> alienCenter, float arcOffsetDeg){
  this->associated = associated;
  std::shared_ptr<GameObject> pointer = alienCenter.lock();
  this->alienCenter = pointer.get();
  this->arc = arcOffsetDeg;
  Sprite* sprite = new Sprite(associated);
  sprite->Open("assets/img/minion.png");
  float scale_sprite = 1 + 0.1*(std::rand()%5);//std::rand() % 10 + 10
  sprite->SetScaleX(scale_sprite);
  sprite->SetScaleY(scale_sprite);
  sprite->SetClip(0, 0, sprite->Sprite::GetHeight() ,sprite->Sprite::GetWidth());
  this->associated->GameObject::AddComponent(sprite);
}

void Minion::Update(float dt){
  float PI = 3.14;
  Vec2 rotation = Vec2(this->alienCenter->box.x , this->alienCenter->box.y);
  rotation.GetRotated( this->arc );//-PI + PI*(rand() % 1001)/500.0
  this->associated->box.x = this->alienCenter->box.x + 200*rotation.x + 163/4;
  this->associated->box.y = this->alienCenter->box.y - 200*rotation.y + 163/4;;
  this->arc = this->arc + PI/48;

  this->associated->angleDeg = this->associated->angleDeg -3.8;
}

void Minion::Render(){

}

bool Minion::Is(std::string type){
  if(type == "Minion"){
    return true;
  }
  else
    return false;
}

void Minion::Shoot(Vec2 target){
  Game* game = Game::getInstance();
  State* StageState = game->getStageState();

  GameObject* bullet_go = new GameObject();
  bullet_go->box.x = this->associated->box.x;
  bullet_go->box.y = this->associated->box.y;
  bullet_go->box.w = 30;
  bullet_go->box.h = 15;
  float angle =atan((-target.y + bullet_go->box.y)/(target.x - bullet_go->box.x) );
  //std::cout << "angulo = "<<-sin(angle)*180/3.14 << std::endl;
  int speed;
  if(target.x >= bullet_go->box.x){
    speed = 15;
    bullet_go->angleDeg = -sin(angle)*180/3.14 ;
  }
  else{
    speed = -15;
    bullet_go->angleDeg = 180 -sin(angle)*180/3.14 ;
  }
  Bullet* bullet = new Bullet(bullet_go, angle, speed, 10, 500,"assets/img/minionbullet2.png");
  bullet_go->GameObject::AddComponent(bullet);
  Collider* bullet_collider = new Collider(bullet_go);
  bullet_go->GameObject::AddComponent(bullet_collider);
  StageState->AddObject(bullet_go);
}

void Minion::Start(){

}
