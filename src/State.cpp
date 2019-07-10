#include"State.h"

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

bool State::GetPopRequested()
{
  return this->popRequested;
}

bool State::GetQuitRequested()
{
  return this->quitRequested;
}

void State::PopRequested()
{
  this->popRequested = true;
}

void State::QuitRequested()
{
  this->quitRequested = true;
}

void State::Pause (){

}

void State::Resume (){

}
