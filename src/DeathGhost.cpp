#include"DeathGhost.h"

DeathGhost::DeathGhost(GameObject* associated,int direction){
  this->associated = associated;
  this->spawnGhost = Vec2(associated->box.x,associated->box.x);
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/fan_img/bg character.png");
  this->associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
  this->restTimer = timer;
  Sound* sound = new Sound(this->associated,"assets/SFX/blade.ogg");
  this->blade = sound;
}

DeathGhost::~DeathGhost(){

}

void DeathGhost::Start(){

}

void DeathGhost::Update(float dt){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  //std::cout << "PlayerPosition" <<fantomeState->PlayerPosition.x<<"    - "<<fantomeState->PlayerPosition.y << '\n';
  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fabs(distanceFantome) <= GameData::followLimit && fantomeState->fantomeExist == true){
    //std::cout << "following" << '\n';
    if(distanceFantome < 0){
      this->associated->box.x = this->associated->box.x - dt* GameData::DeathGhostSpeed.x;
    }else{
      this->associated->box.x = this->associated->box.x + dt* GameData::DeathGhostSpeed.x;
    }
    if(distanceFantome <= 100){
      this->restTimer->Update(dt);
      GhostAttack();
    }
    if(distanceFantome >= -100){
      this->restTimer->Update(dt);
      GhostAttack();
    }
  }else{
    float distanceSpawn = this->spawnGhost.x - this->associated->box.x;
    if(fabs(distanceSpawn) >= 10){
      if(this->spawnGhost.x - this->associated->box.x < 0){
        this->associated->box.x = this->associated->box.x - dt* GameData::DeathGhostSpeed.x;
      }else{
        this->associated->box.x = this->associated->box.x + dt* GameData::DeathGhostSpeed.x;
      }
    }
  }

}

void DeathGhost::GhostAttack(){
  if(this->restTimer->Get() >= 2){
    this->blade->Play(1);
    GameObject* Attack = new GameObject();

    Attack->box.x = this->associated->box.x + 200;
    Attack->box.y = this->associated->box.y + 70;
    Attack->box.w = 100;
    Attack->box.h = 40;
    Sprite* sprite = new Sprite(Attack);
    sprite->Open("assets/img/penguin.png");
    Attack->GameObject::AddComponent(sprite);

    Blade* blade_component = new Blade(Attack,100,100,1);
    Attack->GameObject::AddComponent(blade_component);

    Collider* holyLight_collider = new Collider(Attack);
    //Vec2 offset = Vec2(200,-50);
    //holyLight_collider->SetOffset(offset);
    Attack->GameObject::AddComponent(holyLight_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(Attack);

    std::cout << "ATAAAAAAAAAAAAAAQUE" << '\n';
    this->restTimer->Restart();
  }
}

void DeathGhost::Render(){

}

bool DeathGhost::Is (std::string type){
  return (type == "DeathGhost");
}



void DeathGhost::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
  }
}
