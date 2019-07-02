#include"Collider.h"

Collider::Collider(GameObject* associated, Vec2 scale, Vec2 offset){
  this->scale = scale;
  offset = Vec2(0,0);
  this->associated = associated;
  this->box = this->associated->box;
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Update(float dt){
  //this->box = this->associated->box;
  this->box.x = this->associated->box.x + offset.x;
  this->box.y = this->associated->box.y + offset.y;
  this->box.h = this->associated->box.h + this->scale.y;
  this->box.w = this->associated->box.w + this->scale.x;
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Render(){
  Vec2 center = this->box.GetCenter();

  SDL_Point points[5];

  float angle = this->associated->angleDeg/(180/PI);

  Vec2 point = (Vec2(this->box.x, this->box.y) - center).GetRotated(angle) + center + Camera::pos;
  points[0] = {(int)point.x, (int)point.y};
  points[4] = {(int)point.x, (int)point.y};

  point = (Vec2(this->box.x + this->box.w, this->box.y) - center).GetRotated(angle)	+ center + Camera::pos;
  points[1] = {(int)point.x, (int)point.y};

  point = (Vec2(this->box.x + this->box.w, this->box.y + this->box.h) - center).GetRotated(angle)	+ center + Camera::pos;
  points[2] = {(int)point.x, (int)point.y};

  point = (Vec2(this->box.x, this->box.y + this->box.h) - center).GetRotated(angle) + center + Camera::pos;
  points[3] = {(int)point.x, (int)point.y};

  SDL_SetRenderDrawColor(Game::GetInstance()->GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLines(Game::GetInstance()->GetRenderer(), points, 5);
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
