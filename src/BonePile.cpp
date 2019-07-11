#include"BonePile.h"

BonePile::BonePile(GameObject* associated,int walkLimit){
  this->associated = associated;
  this->spawnBone = Vec2(associated->box.x,associated->box.x);
  this->walkLimitRigth = associated->box.x + walkLimit;
  this->walkLimitLeft =  associated->box.x - walkLimit;
  this->direction = 0;
  Sprite* sprite = new Sprite(this->associated, "assets/img/bonefrog/wild/walkingWildBoneFrog.png", 12, 0.05, 0);
  this->associated->AddComponent(sprite);
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
    /*GameObject* boneFrog2 = new GameObject();
    boneFrog2->box.w = 100;
    boneFrog2->box.h = 30;
    boneFrog2->box.x = this->associated->box.x;
    boneFrog2->box.y = this->associated->box.y;
    BoneFrog* boneFrog_component = new BoneFrog(boneFrog2);
    boneFrog2->GameObject::AddComponent(boneFrog_component);
    Sprite* boneFrogsprite = new Sprite(boneFrog2);
    boneFrogsprite->Open(assets/img/penguin/cubngun.png");
    boneFrog2->GameObject::AddComponent(boneFrogsprite);
    Collider* boneFrog_collider = new Collider(boneFrog2);
    boneFrog2->GameObject::AddComponent(boneFrog_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(boneFrog2);
*/

    this->associated->RequestDelete();
  }
}
