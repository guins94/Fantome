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

  if(this->restTimer->Get() >= 1){
    FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

    fantomeState->fantomeExist = true;
    GameObject* goFantome = new GameObject();

    Sprite* sprite = new Sprite(goFantome, "assets/img/fantome/standingFantome.png", 6, 0.1, 0);
    goFantome->GameObject::AddComponent(sprite);
    goFantome->box.x = this->associated->box.x;
    goFantome->box.y = this->associated->box.y;
    goFantome->box.w = sprite->GetHeight();
    goFantome->box.h = sprite->GetWidth();
    //goFantome->box.h = 50;

    Fantome* fantome_component = new Fantome(goFantome);
    goFantome->GameObject::AddComponent(fantome_component);

    Collider* fantome_collider = new Collider(goFantome);
    //Vec2 offset = Vec2(0,120);
    //fantome_collider->SetOffset(offset);
    goFantome->GameObject::AddComponent(fantome_collider);

    Game::GetInstance()->GetCurrentState()->AddObject(goFantome);

    this->restTimer->Restart();
    Camera::Follow(goFantome);
    this->associated->RequestDelete();
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
