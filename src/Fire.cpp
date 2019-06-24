#include"Fire.h"

Fire::Fire(GameObject* associated){
  this->associated = associated;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/img/minionbullet1.png");
  this->associated->GameObject::AddComponent(sprite);
  Sound* sound = new Sound(this->associated,"assets/SFX/fire.ogg");
  this->fireSound = sound;
  //sound->Play(1);
  Timer* timer = new Timer();
  this->restTimer = timer;
}

Fire::~Fire(){

}

void Fire::Start(){

}

void Fire::Update(float dt){
  this->restTimer->Update(dt);
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fabs(distanceFantome) <= 300 && fantomeState->fantomeExist == true){
    if(this->restTimer->Get() >= 5){
      this->fireSound->Play(1);
      this->restTimer->Restart();
    }
  }else{
    this->fireSound->Stop();
  }

}

void Fire::Render(){

}

bool Fire::Is (std::string type){
  return (type == "Fire");
}



void Fire::NotifyCollision(GameObject& other){
  if(other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
      fantomeState->nFire += 1;
      Camera::Follow(nullptr);
      this->associated->RequestDelete();
      fantomeState->fantomeExist = false;
    }
  }
}
