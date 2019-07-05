#include"Possession.h"

Possession::Possession(GameObject* associated,int direction){
  this->associated = associated;
  this->direction = direction;
  //Sprite* sprite = new Sprite(this->associated);
  //sprite->Open("assets/img/penguinface.png");
  //associated->GameObject::AddComponent(sprite);
  Sound* sound = new Sound(this->associated,"assets/SFX/possess.ogg");
  sound->Play(1);
  Timer* timer = new Timer();
  this->restTimer = timer;
}

Possession::~Possession(){

}

void Possession::Start(){

}

void Possession::Update(float dt){
  this->restTimer->Update(dt);

  this->associated->box.y -= 5;

  if(this->restTimer->Get() >= 1)
  {
    /* Retrieving Current State */
    FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

    /* Creating New Fantome */
    GameObject* goFantome = new GameObject();
    goFantome->box.x = this->associated->box.x;
    goFantome->box.y = this->associated->box.y;

    Fantome* fantome = new Fantome(goFantome);
    goFantome->AddComponent(fantome);

    Collider* fantomeCollider = new Collider(goFantome, Vec2(1,1), Vec2(0,0));
    goFantome->AddComponent(fantomeCollider);

    fantomeState->AddObject(goFantome);

    this->restTimer->Restart();
    this->associated->RequestDelete();

    /* Following Fantome */
    Camera::Follow(goFantome);
  }

}

void Possession::Render(){

}

bool Possession::Is (std::string type){
  return (type == "Fantome");
}



void Possession::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
    this->falling = false;
  }

  if(other.GetComponent("Grave") != nullptr){
    this->restTimer->Restart();
  }
}
