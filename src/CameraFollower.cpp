#include "CameraFollower.h"


CameraFollower::CameraFollower(GameObject* go){
  this->associated = go;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/img/bg_final_1.png");
  //sprite->Open("assets/img/bg_test.png");
  this->associated->GameObject::AddComponent(sprite);
}

void CameraFollower::Update(float dt){
  //Camera* camera = Camera::GetInstance();
  //this->associated->box.x = 0;
  //this->associated->box.y = 0;

  float deltaTime = dt * Camera::speed.x;

  this->associated->box.x = - Camera::pos.x;
  this->associated->box.y = - Camera::pos.y;

  if(InputManager::GetInstance()->IsKeyDown(SDLK_RIGHT))
  this->associated->box.x = - Camera::pos.x + deltaTime;
  if(InputManager::GetInstance()->IsKeyDown(SDLK_LEFT))
  this->associated->box.x = - Camera::pos.x - deltaTime;
  if(InputManager::GetInstance()->IsKeyDown(SDLK_UP))
  this->associated->box.y = - Camera::pos.y - deltaTime;
  if(InputManager::GetInstance()->IsKeyDown(SDLK_DOWN))
  this->associated->box.y = - Camera::pos.y + deltaTime;

  if(InputManager::GetInstance()->IsKeyDown(SDLK_RIGHT) && InputManager::GetInstance()->IsKeyDown(SDLK_LEFT))
  this->associated->box.x = - Camera::pos.x;

  if(InputManager::GetInstance()->IsKeyDown(SDLK_DOWN) && InputManager::GetInstance()->IsKeyDown(SDLK_UP))
  this->associated->box.y = - Camera::pos.y;
  }

void CameraFollower::Render(){

}

void CameraFollower::Start(){

}

bool CameraFollower::Is(std::string type){
  if(type == "CameraFollower"){
		return true;
	}
	else
		return false;
}
