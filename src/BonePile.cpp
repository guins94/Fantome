#include"BonePile.h"

BonePile::BonePile(GameObject* associated,int walkLimit){
  this->associated = associated;
  this->spawnBone = Vec2(associated->box.x,associated->box.x);
  this->walkLimitRigth = associated->box.x + walkLimit;
  this->walkLimitLeft =  associated->box.x - walkLimit;
  this->direction = 0;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/img/minion.png");
  this->associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
  this->restTimer = timer;
}

BonePile::~BonePile(){

}

void BonePile::Start(){

}

void BonePile::Update(float dt){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  switch (this->direction) {
    case MOVERIGHT:
      //std::cout << "walking right" << '\n';
      this->associated->box.x = this->associated->box.x + dt* GameData::fantomeSpeed.x;
      break;
    case MOVELEFT:
      //std::cout << "walking left" << '\n';
      this->associated->box.x = this->associated->box.x - dt* GameData::fantomeSpeed.x;
      break;
    default:
      break;
    }

    if(this->walkLimitRigth <= this->associated->box.x){
      this->direction = MOVELEFT;
    }

    if(this->walkLimitLeft >= this->associated->box.x){
      this->direction = MOVERIGHT;
    }

}

void BonePile::Render(){

}

bool BonePile::Is (std::string type){
  return (type == "BonePile");
}



void BonePile::NotifyCollision(GameObject& other){
	if(other.GetComponent("Grave")){
    GameObject* boneFrog = new GameObject();
    boneFrog->box.w = 100;
    boneFrog->box.h = 30;
    boneFrog->box.x = this->associated->box.x;
    boneFrog->box.y = 700;
    BoneFrog* boneFrog_component = new BoneFrog(boneFrog);
    boneFrog->GameObject::AddComponent(boneFrog_component);
    Sprite* boneFrogsprite = new Sprite(boneFrog);
    boneFrogsprite->Open("assets/img/cubngun.png");
    boneFrog->GameObject::AddComponent(boneFrogsprite);
    Collider* boneFrog_collider = new Collider(boneFrog);
    boneFrog->GameObject::AddComponent(boneFrog_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(boneFrog);


    this->associated->RequestDelete();
  }
}
