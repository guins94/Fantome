#include "Camera.h"

GameObject* Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

/*
Camera::Camera(){
  this->focus = nullptr;
  GameObject* go = new GameObject();
  go->box.x = 0;
  go->box.y = 0;
  go->box.w = 0;
  go->box.h = 0;
  this->focus = go;
}*/

void Camera::Follow(GameObject* newFocus){
  focus = newFocus;
  //pos.x = focus->box.x;
  //pos.y = focus->box.y;
}

void Camera::Unfollow(){
  focus = nullptr;
}

void Camera::Update(float dt){

  speed = Vec2(200, 200);
  InputManager* inputManager = InputManager::GetInstance();

  if(focus){
    pos.x = Game::GetInstance()->width/2 - Camera::focus->box.x - Camera::focus->box.w/2 ;
    pos.y = Game::GetInstance()->height/2 - Camera::focus->box.y - Camera::focus->box.h/2 + 100;
    /*if(pos.y<= -36 ){
      pos.y = -36;
    }*/
    //std::cout <<" CAMERA Y " << pos.y << '\n';
  } else {
    if(inputManager->KeyRelease(SDLK_RIGHT)){
      pos.x += dt * speed.x;
    }
    if(inputManager->KeyRelease(SDLK_LEFT)){
      pos.x -= dt * speed.x;
    }
    if(inputManager->KeyRelease(SDLK_UP)){
      pos.y -= dt * speed.y;
    }
    if(inputManager->KeyRelease(SDLK_DOWN)){
      pos.y += dt * speed.y ;
    }
  }

  //InputManager* inputManager = InputManager::GetInstance();

  /*if(inputManager->KeyRelease(SDLK_a) == false){
    pos.x = (pos.x + dt);
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    pos.x = (pos.x - dt);
  }
  if(inputManager->KeyRelease(SDLK_w) == false){
    this->pos.y= (this->pos.y + dt);
  }
  if(inputManager->KeyRelease(SDLK_s) == false){
    this->pos.y= (this->pos.y - dt);
  }*/

  //speed = Vec2(0,0);

}
/*
Camera* Camera::GetInstance(){
  static Camera instance;
  return &instance;
}*/
