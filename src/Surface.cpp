#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<memory>
#include<string>

#include"Sprite.h"
#include"Surface.h"
#include"InputManager.h"

using namespace std;


Surface::Surface(GameObject* associated){
  this->associated = associated;

}

void Surface::Load(std::string file){
}

int* Surface::At(int x,int y, int z){

}

void Surface::Render(){

}

void Surface::Start(){

}

void Surface::RenderLayer(int layer, int cameraX, int CameraY){

}

void Surface::Update(float dt){
  InputManager* inputManager = InputManager::GetInstance();
  if(inputManager->KeyRelease(SDLK_a) == false){
    this->associated->box.x = this->associated->box.x + dt;
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    this->associated->box.x = this->associated->box.x - dt;
  }
}

bool Surface::Is(std::string type){
	if(type == "Surface"){
		return true;
	}else{
		return false;
	}
}
