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
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Render(){
  	SDL_Point points[5];

  	points[0] = {(int)this->associated->box.x, (int)this->associated->box.y};
  	points[4] = {(int)this->associated->box.x, (int)this->associated->box.y};

  	points[1] = {(int)this->associated->box.x + this->associated->box.w, (int)this->associated->box.y};

  	points[2] = {(int)this->associated->box.x + this->associated->box.w, (int)this->associated->box.y + this->associated->box.h};

  	points[3] = {(int)this->associated->box.x, (int)this->associated->box.y + this->associated->box.h};

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

}

void Collider::SetOffset(Vec2 offset){

}
