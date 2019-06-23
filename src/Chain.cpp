#include "Chain.h"

Chain::Chain(GameObject* associated) : Component(associated)
{
  this->associated = associated;

  /* Adicionando Sprite */
 Sprite* sprite = new Sprite(associated, 1, 0);
 sprite->Open("assets/img/minionbullet1.png");
 this->associated->box.w = sprite->GetHeight();
 this->associated->box.h = sprite->GetWidth();
 this->associated->AddComponent(sprite);

 /* Adicionando Collider */
 Collider* collider = new Collider(associated, Vec2(1,1), Vec2(0,0));
 this->associated->AddComponent(collider);

}

Chain::~Chain()
{

}

void Chain::Update(float dt)
{

}

void Chain::Render()
{

}

void Chain::Start()
{

}

bool Chain::Is(std::string type)
{
  if(type == "Chain"){
    return true;
  }
  else
    return false;
}

void Chain::NotifyCollision(GameObject& other)
{

}
