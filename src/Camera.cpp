#include "SDL2/SDL.h"

#include"Vec2.h"
#include"Camera.h"
#include"InputManager.h"

#include"GameObject.h"

Camera::Camera(){
  this->focus = nullptr;
  GameObject* go = new GameObject();
  go->box.x = 0;
  go->box.y = 0;
  go->box.w = 0;
  go->box.h = 0;
  this->focus = go;
}

void Camera::Follow(GameObject* focus){
  this->focus = focus;
  this->pos.x = focus->box.x;
  this->pos.y = focus->box.y;
}

void Camera::Unfollow(){
  this->focus = nullptr;
}

void Camera::Update(float dt){
  InputManager* inputManager = InputManager::GetInstance();

  if(inputManager->KeyRelease(SDLK_a) == false){
    this->pos.x = (this->pos.x + dt);
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    this->pos.x= (this->pos.x - dt);
  }
  if(inputManager->KeyRelease(SDLK_w) == false){
    this->pos.y= (this->pos.y + dt);
  }
  if(inputManager->KeyRelease(SDLK_s) == false){
    this->pos.y= (this->pos.y - dt);
  }


  this->speed = Vec2(0,0);

}

Camera* Camera::GetInstance(){
  static Camera instance;
  return &instance;
}
