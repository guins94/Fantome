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
#include"EndState.h"
#include"StageState.h"


EndState::EndState(){
  GameObject* Title = new GameObject();
  Title->box.w = 0;
  Title->box.h = 0;
  Title->box.x = 0;
  Title->box.y = 0;
  Sprite* Title_sprite = new Sprite(Title);
  Title_sprite->Open("assets/img/win.jpg");
  Title->GameObject::AddComponent(Title_sprite);
  this->objectArray.emplace_back(Title);
}


EndState::~EndState(){
	this->objectArray.clear();
}

void EndState::LoadAssets(){

}


void EndState::Render(){
  for(int x = 0; x<=this->objectArray.size() - 1; x++){
    objectArray[x]->Render();
  }
}

void EndState::AddObject(int mouseX,int mouseY){
}

void EndState::Start(){
  for(int i = 0;i <= this->objectArray.size() -1; i++){
    //std::cout << "start em StageState \n"<< std::endl;
    this->objectArray[i]->Start();
  }
  this->started = true;
}

std::weak_ptr<GameObject> EndState::AddObject(GameObject* go){
}

std::weak_ptr<GameObject> EndState::GetObjectPtr(GameObject* go){
}


void EndState::Update(){
  InputManager* inputManager = InputManager::GetInstance();
  //inputManager->MousePress(SDL_BUTTON_LEFT) == true
  //inputManager->KeyRelease(SDLK_SPACE) == false
  if(inputManager->KeyRelease(SDLK_SPACE) == false){
    Game* instance = Game::getInstance();
    instance->Push(new TitleState());
    //State::PopRequested();
    State::QuitRequested();
  }
}
void EndState::StartArray(){

}

void EndState::UpdateArray(float dt){

}

void EndState::RenderArray(){

}

bool EndState::PopRequested(){

}

bool EndState::QuitRequested(){

}


void EndState::Pause (){

}

void EndState::Resume (){

}
