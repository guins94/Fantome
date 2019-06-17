#include"DeathGhost.h"

DeathGhost::DeathGhost(GameObject* associated,int direction){
  this->associated = associated;
  this->spawnGhost = Vec2(associated->box.x,associated->box.x);
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/fan_img/bg character.png");
  this->associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
  this->restTimer = timer;
}

DeathGhost::~DeathGhost(){

}

void DeathGhost::Start(){

}

void DeathGhost::Update(float dt){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  std::cout << "PlayerPosition" <<fantomeState->PlayerPosition.x<<"    - "<<fantomeState->PlayerPosition.y << '\n';
  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fabs(distanceFantome) <= GameData::followLimit && fantomeState->fantomeExist == true){
    std::cout << "following" << '\n';
    if(distanceFantome < 0){
      this->associated->box.x = this->associated->box.x - dt* GameData::DeathGhostSpeed.x;
    }else{
      this->associated->box.x = this->associated->box.x + dt* GameData::DeathGhostSpeed.x;
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

void DeathGhost::Render(){

}

bool DeathGhost::Is (std::string type){
  return (type == "DeathGhost");
}



void DeathGhost::NotifyCollision(GameObject& other){
	if(other.GetComponent("Ground") != nullptr){
  }
}
