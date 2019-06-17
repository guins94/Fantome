#include "Fantome.h"

Fantome::Fantome(GameObject* associated){
  this->associated = associated;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->associated->futureBox = this->associated->box;
}

Fantome::~Fantome(){

}

void Fantome::Start(){

}

void Fantome::Update(float dt){

  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  fantomeState->fantomeExist = true;

  Rect auxBox = this->associated->futureBox;

  /* Calculando eixo y da futura posição do Fantome */
  this->associated->futureBox.y = this->associated->futureBox.y + dt * GameData::fantomeSpeed.y;
  if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
    this->associated->box.y = this->associated->futureBox.y;
  this->associated->futureBox = auxBox;

  /* Calculando eixo x da futura posição do Fantome */
  InputManager* inputManager = InputManager::GetInstance();
  if(!inputManager->KeyRelease(SDLK_a)){
    this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::fantomeSpeed.x;
    if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
      this->associated->box.x = this->associated->futureBox.x;
    this->associated->futureBox = auxBox;
  }
  if(!inputManager->KeyRelease(SDLK_d)){
    this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::fantomeSpeed.x;
    if(!fantomeState->WillCollideWithGround(this->associated->futureBox))
      this->associated->box.x = this->associated->futureBox.x;
    this->associated->futureBox = auxBox;
  }

  this->associated->futureBox = this->associated->box;
}

void Fantome::Render(){

}

bool Fantome::Is(std::string type){
  return (type == "Fantome");
}

void Fantome::NotifyCollision(GameObject& other){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Tratamento de colisão caso Fantome colida com o chão */
	if(other.GetComponent("Collider") && other.GetComponent("Ground")){
    std::cout << "COLIDIU COM O CHÃO" << '\n';
    //this->falling = false;
  }

  if(other.GetComponent("Grave")){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      this->associated->RequestDelete();
      fantomeState->fantomeExist = false;
    }
  }

  if(other.GetComponent("BoneFrog")){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      this->associated->RequestDelete();
      fantomeState->fantomeExist = false;
    }
  }

  if(other.GetComponent("Chains")){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      this->associated->RequestDelete();
      fantomeState->fantomeExist = false;
    }
  }
/*
  if(other.GetComponent("HolyLight")){
      Camera::Follow(nullptr);
      this->associated->RequestDelete();
      fantomeState->fantomeExist = false;
  }*/
}
