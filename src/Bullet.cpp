#include<iostream>
#include<vector>
#include<string>
#include <cmath>

#include"Rect.h"
#include"Component.h"
#include"Bullet.h"
#include"Sprite.h"


Bullet::Bullet(GameObject* associated, float angle, float speed, int damage, float maxDistance, std::string sprite){
  this->associated = associated;
  this->distanceLeft = maxDistance;
  this->damage = damage;
  Sprite* bullet_sprite = new Sprite(this->associated,4,30);
  bullet_sprite->Open(sprite); //"assets/img/minionbullet1.png"
  this->associated->GameObject::AddComponent(bullet_sprite);
  this->speed.x = cos(angle)*speed;
  this->speed.y = sin(angle)*speed;
  //std::cout << cos(angle)<<std::endl;
  if(sprite == "assets/img/penguinbullet.png")
    targetsPlayer = true;
  else
    targetsPlayer = false;
}

void Bullet::Update(float dt){
  this->associated->box.x = this->associated->box.x + this->speed.x;
  this->associated->box.y = this->associated->box.y - this->speed.y;
  this->distanceLeft = this->distanceLeft - sqrt(this->speed.x*this->speed.x + this->speed.y*this->speed.y);
  if(this->distanceLeft <= 0){
    this->associated->RequestDelete();//destroi bullet
  }
}

void Bullet::Render(){

}

bool Bullet::Is(std::string type){
  if(type == "Bullet"){
    return true;
  }
  else
    return false;
}

int Bullet::GetDamage(){
  return this->damage;
}

void Bullet::Start(){

}

void Bullet::NotifyCollision(GameObject& other){
  if(other.GetComponent("PenguinBody") != nullptr && targetsPlayer == false){
    std::cout << "PENGUIM HIT BULLEET " << std::endl;
    this->associated->RequestDelete();
  }
  if(other.GetComponent("Alien") != nullptr && targetsPlayer == true){
    std::cout << "Alien HIT BULLEET " << std::endl;
    this->associated->RequestDelete();
  }
}
