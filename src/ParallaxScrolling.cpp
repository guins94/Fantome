#include "ParallaxScrolling.h"

ParallaxScrolling::ParallaxScrolling(GameObject* associated, float multiplier, std::string sprite_file){
  this->associated = associated;
  this->multiplier = multiplier;
  this->parallaxSprite = new Sprite();
  this->parallaxSprite->Open(sprite_file);
}

ParallaxScrolling::ParallaxScrolling(GameObject* associated, float multiplier, std::string sprite_file, int frameCount){
  this->associated = associated;
  this->multiplier = multiplier;
  this->parallaxSprite = new Sprite(this->associated, sprite_file, frameCount, 0.1, 0);
}

void ParallaxScrolling::SetTileSet(Sprite* parallaxSprite){
	this->parallaxSprite = parallaxSprite;
}

void ParallaxScrolling::Render()
{
  this->parallaxSprite->SetClip(0, 0, this->parallaxSprite->GetHeight(), 600);

  std::cout << "Camera X: " << Camera::pos.x << '\n';

  if(Camera::pos.x >= 0)
  {
    std::cout << "Render 0 0" << '\n';
    this->parallaxSprite->Render(0, 0);
  }
  else
    this->parallaxSprite->Render(Camera::pos.x * this->multiplier, 0);
}

void ParallaxScrolling::Start()
{

}

void ParallaxScrolling::Update(float dt)
{

}

bool ParallaxScrolling::Is(std::string type)
{

}

void ParallaxScrolling::NotifyCollision()
{

}
