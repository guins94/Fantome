#include "SDL2/SDL.h"

#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include"Sound.h"
#include"Face.h"
#include"InputManager.h"
#include"Camera.h"
//#include"GameObject.h"
Face::Face(GameObject* associated){
	this->associated = associated;
	this->hitpoints = 30;
	//std::cout << "Construindo.\n" <<this->hitpoints<< std::endl;
}

void Face::Damage(int damage){
	this->hitpoints = 30;
	//std::cout << "Destruindo FACE.\n" <<this->hitpoints<< std::endl;
	this->hitpoints = this->hitpoints - damage;
	//std::cout << "Destruindo FACE.\n" <<this->hitpoints<< std::endl;
	if(this->hitpoints <= 0){

		Sound* boom = (Sound*)this->associated->GetComponent("Sound");
		if(nullptr != boom){
		boom->Play(-1);
		}
		this->associated->RequestDelete();
		//associated->Play();
	}
}

void Face::Update(float dt){
	InputManager* inputManager = InputManager::GetInstance();
	//Camera* camera = Camera::GetInstance();
	if(inputManager->KeyRelease(SDLK_LEFT) == false){
    this->associated->box.x = this->associated->box.x + dt;
  }
  if(inputManager->KeyRelease(SDLK_RIGHT) == false){
    this->associated->box.x = this->associated->box.x - dt;
  }
  if(inputManager->KeyRelease(SDLK_UP) == false){
    this->associated->box.y = this->associated->box.y + dt;
  }
  if(inputManager->KeyRelease(SDLK_DOWN) == false){
    this->associated->box.y = this->associated->box.y - dt;
  }
}

void Face::Render(){

}

void Face::Start(){

}

bool Face::Is(std::string type){
	if(type == "Face"){
		return true;
	}
	else
		return false;
}
