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
#include <iostream>
#include<string>
#include <algorithm>


Collider::Collider(GameObject* associated, Vec2 scale, Vec2 offset){
  scale = Vec2(1,1);
  offset = Vec2(1,1);
  this->associated = associated;
  this->box = this->associated->box;
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Update(float dt){
  this->box = this->associated->box;
  this->box.x = this->box.x + offset.x;
  this->box.y = this->box.y + offset.y;
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Render(){
  	SDL_Point points[5];

  	points[0] = {(int)this->box.x, (int)this->box.y};
  	points[4] = {(int)this->box.x, (int)this->box.y};

  	points[1] = {(int)this->box.x + this->box.w, (int)this->box.y};

  	points[2] = {(int)this->box.x + this->box.w, (int)this->box.y + this->box.h};

  	points[3] = {(int)this->box.x, (int)this->box.y + this->box.h};

  	SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
  	SDL_RenderDrawLines(Game::getInstance()->getRenderer(), points, 5);
}

bool Collider::Is(std::string type){
  if(type == "Collider"){
		return true;
	}else{
		return false;
	}
}

void Collider::SetScale(Vec2 scale){
  this->scale.y = scale.y;
  this->scale.x = scale.x;
}

void Collider::SetOffset(Vec2 offset){
  this->offset.y = offset.y;
  this->offset.x = offset.x;
}
