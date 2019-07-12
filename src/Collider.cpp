#include"Collider.h"

Collider::Collider(GameObject* associated, Vec2 scale, Vec2 offset)
{
  /* Creating Link Between Collider Component and GameObject */
  this->associated = associated;

  /* Initializing Collider Variables */
  this->scale = scale;
  this->offset = offset;
  this->box = this->associated->box;
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Start()
{

}

//TODO: Fix collider scale
void Collider::Update(float dt)
{
  /* The Collider Copies the GameObject's Box and Adds Offset and Scale */
  this->box.x = this->associated->box.x + this->offset.x;
  this->box.y = this->associated->box.y + this->offset.y;
  this->box.h = this->associated->box.h* this->scale.y;
  this->box.w = this->associated->box.w* this->scale.x;

  /* Collider Angle is the Same as The GameObject's Angle */
  this->angleDeg = this->associated->angleDeg;
}

void Collider::Render()
{
  /*Vec2 center = this->box.GetCenter();

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
  SDL_RenderDrawLines(Game::GetInstance()->GetRenderer(), points, 5);*/
}

bool Collider::Is(std::string type)
{
  return (type == "Collider");
}

void Collider::NotifyCollision()
{

}

void Collider::SetScale(Vec2 scale){
  this->scale = scale;
}

void Collider::SetOffset(Vec2 offset){
  this->offset = offset;
}
