#include<vector>
#include<iostream>
#include<memory>
#include<string>
#include<map>
#include<queue>
#include<algorithm>

#include"State.h"
#include"Face.h"
#include"Vec2.h"
#include"Sound.h"
#include"TileMap.h"
#include"InputManager.h"
#include"Camera.h"
#include"GAME.h"
#include"CameraFollower.h"
#include"Alien.h"
#include"Minion.h"
#include"Bullet.h"
#include"PenguinBody.h"
#include"PenguinCannon.h"
#include"Collider.h"


#include"SDL2/SDL.h"
#include"SDL2/SDL_image.h"
#include"SDL2/SDL_mixer.h"
#include"SDL2/SDL_ttf.h"


State::State(){
  this->popRequested = false;
  this->quitRequested = false;
  this->started = false;
}

State::~State(){
	this->objectArray.clear();
}

void State::LoadAssets(){

}


void State::Render(){

}


void State::Start(){

}

std::weak_ptr<GameObject> State::AddObject(GameObject* go){
  auto gameObject = std::shared_ptr<GameObject>(go);
  this->objectArray.emplace_back(gameObject);
  std::weak_ptr <GameObject > pointer = gameObject;
  if(this->started == true){
    go->Start();
  }
  return pointer;
}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    if(this->objectArray[x].get() == go){
      std::weak_ptr <GameObject > pointer = this->objectArray[x];
      return pointer;
    }
  }
  return std::weak_ptr<GameObject>();
}


void State::Update(){

}
void State::StartArray(){

}

void State::UpdateArray(float dt){

}

void State::RenderArray(){

}

bool State::GetPopRequested(){
  //std::cout << "poprequest de state \n"<< std::endl;
  return this->popRequested;
}

void State::PopRequested(){
  this->popRequested = true;
}

bool State::GetQuitRequested(){
    return this->quitRequested;
}

void State::QuitRequested(){
  this->quitRequested = true;
}

void State::Pause (){

}

void State::Resume (){

}
