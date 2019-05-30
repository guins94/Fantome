#include "SDL2/SDL.h"

#include"Vec2.h"
#include"Camera.h"
#include"InputManager.h"
#include"Sprite.h"

#include"GameObject.h"
#include"CameraFollower.h"
#include"Camera.h"

CameraFollower::CameraFollower(GameObject* go){
  this->associated = go;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/fan_img/bg_test_pequeno.png");
  //sprite->Open("assets/fan_img/bg_test.png");
  this->associated->GameObject::AddComponent(sprite);
}

void CameraFollower::Update(float dt){
  //Camera* camera = Camera::GetInstance();
  this->associated->box.x = 0;
  this->associated->box.y = 0;
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
/*
Camera* Camera::GetInstance(){
  static Camera instance;
  return &instance;
}*/
