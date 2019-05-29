#include<vector>
#include<iostream>
#include<memory>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<memory>

#include"Component.h"
#include"Vec2.h"
#include"GameObject.h"
#include"TitleState.h"
#include"GameObject.h"
#include"InputManager.h"
#include"GAME.h"


TitleState::TitleState(){
  GameObject* Title = new GameObject();
  Title->box.w = 0;
  Title->box.h = 0;
  Title->box.x = 0;
  Title->box.y = 0;
  Sprite* Title_sprite = new Sprite(Title);
  Title_sprite->Open("assets/img/title.jpg");
  Title->GameObject::AddComponent(Title_sprite);
  this->objectArray.emplace_back(Title);
}


TitleState::~TitleState(){
	this->objectArray.clear();
}

void TitleState::LoadAssets(){

}


void TitleState::Render(){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Render();
  }
}

void TitleState::AddObject(int mouseX,int mouseY){
}

void TitleState::Start(){
  for(int i = 0;i <= this->objectArray.size() -1; i++){
    //std::cout << "start em StageState \n"<< std::endl;
    this->objectArray[i]->Start();
  }
  this->started = true;
}

std::weak_ptr<GameObject> TitleState::AddObject(GameObject* go){
}

std::weak_ptr<GameObject> TitleState::GetObjectPtr(GameObject* go){
}


void TitleState::Update(){
  InputManager* inputManager = InputManager::GetInstance();
  //inputManager->MousePress(SDL_BUTTON_LEFT) == true
  if(inputManager->KeyRelease(SDLK_SPACE) == false){
    Game* instance = Game::getInstance();
    instance->Push(new StageState());
    //State::PopRequested();
    State::QuitRequested();
  }
}
void TitleState::StartArray(){

}

void TitleState::UpdateArray(float dt){

}

void TitleState::RenderArray(){

}

bool TitleState::PopRequested(){

}

bool TitleState::QuitRequested(){

}


void TitleState::Pause (){

}

void TitleState::Resume (){

}
