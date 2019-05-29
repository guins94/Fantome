#include"Alien.h"

#include"InputManager.h"
#include"Camera.h"
#include"Sprite.h"
#include"Minion.h"
#include"GAME.h"
#include"StageState.h"
#include"Bullet.h"
#include"PenguinBody.h"

#include<queue>

Alien::Alien(GameObject* associated, int nMinions,GameObject* player){
  this->associated = associated;
  this->hp = 50;
  this->nMinions = nMinions;
  this->nMovements = 0;
  Sprite* sprite = new Sprite(this->associated);
  sprite->Open("assets/img/alien.png");
  //std::cout << "width = "<<sprite->GetWidth() << std::endl;
  //this->associated->box.w = sprite->GetWidth();
  //this->associated->box.h = sprite->GetHeight();
  associated->GameObject::AddComponent(sprite);
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->player = player;
}

Alien::~Alien(){
  this->minionArray.clear();
}

void Alien::Start(){
  //std::cout << "alien start \n"<< std::endl;
  Game* game = Game::getInstance();

  float angle_minion = 6.28/nMinions;

  for (int i = 0; i <= this->nMinions-1; i++){
    //std::cout << i << std::endl;
    GameObject* minion_go = new GameObject();
    Minion* minion = new Minion(minion_go, game->getStageState()->GetObjectPtr(this->associated),angle_minion*(i-1));
    minion_go->GameObject::AddComponent(minion);
    minionArray.push_back(game->getStageState()->AddObject(minion_go));
  }
}

void Alien::Update(float dt){
  //std::cout << this->restTimer->Get() << std::endl;
  if(this->restTimer->Get() == 0){
    ActionType move = MOVE;
    Action action = Action(move,std::rand()%500, std::rand()%500);
    this->taskQueue.push(action);
  }

  this->restTimer->Update(dt);

  if(this->taskQueue.empty() == true){
    ActionType shoot = SHOOT;

    //GameObject* Game::getInstance()->getStageState()->GetObjectPtr();
    //Collider* collider_i = (Collider*)objectArray[i]->GetComponent("Collider");
    Action action = Action(shoot,this->player->box.x, this->player->box.y);
    this->taskQueue.push(action);
    this->restTimer->Restart();
  }

  if(this->taskQueue.empty() != true){
    if(this->taskQueue.front().type == MOVE){
      if(this->speed.x == 0){
        this->speed.Speed(this->associated->box.x,this->associated->box.y, this->taskQueue.front().pos.x, this->taskQueue.front().pos.y);
        this->nMovements = -(abs(this->associated->box.x + this->speed.x) - abs(this->taskQueue.front().pos.x) )/ this->speed.x;
        //std::cout  << "n movimentos"<< this->nMovements<<std::endl;
      }
      if(this->nMovements == 0 ){
        this->nMovements--;
        this->associated->box.x = this->associated->box.x + this->speed.x;
        this->associated->box.y = this->associated->box.y - this->speed.y;
        taskQueue.pop();
        this->speed.x = 0;
        this->speed.y = 0;
      }else{
        this->nMovements--;
        this->associated->box.x = this->associated->box.x + this->speed.x;
        this->associated->box.y = this->associated->box.y - this->speed.y;
      }
    }
  }

  if(this->taskQueue.empty() != true){
    if(this->taskQueue.front().type == SHOOT){
      if(this->minionArray.empty() != true){
        //std::cout  << "nminions"<<this->minionArray.size() <<std::endl;
        GameObject* nearest_minion= this->minionArray.front().lock().get();
        float distance_from_shoot = abs(this->taskQueue.front().pos.x - nearest_minion->box.x );
        for(int i = 0;i <= (this->minionArray.size()-1);i++){
          //std::cout  << "niterações "<<i <<std::endl;
          GameObject* comparing_minion= this->minionArray[i].lock().get();
          if(distance_from_shoot >= abs( this->taskQueue.front().pos.x - comparing_minion->box.x)){
            nearest_minion = comparing_minion;
          }
          distance_from_shoot = abs(this->taskQueue.front().pos.x - nearest_minion->box.x );

        }


        //std::shared_ptr<GameObject> pointer = nearest_minion.lock();
        //GameObject* minion_go= pointer.get();
        Minion* minion = (Minion*)nearest_minion->GetComponent("Minion");
        minion->Shoot(this->taskQueue.front().pos);
      }
      taskQueue.pop();
    }
  }

  if(this->hp <= 0){
    while(minionArray.empty() != true){
      GameObject* go = minionArray.back().lock().get();
      go->RequestDelete();
      minionArray.pop_back();
    }
    Game* game = Game::getInstance();
    GameObject* boom = new GameObject();
    boom->box.x = this->associated->box.x;
    boom->box.y = this->associated->box.y;
    Sprite* sprite_boom = new Sprite(boom,4,30);//new Minion(minion_go, game->getStageState()->GetObjectPtr(this->associated),angle_minion*(i-1));
    sprite_boom->Open("assets/img/aliendeath.png");
    sprite_boom->secondsToSelfDestruct = 100;
    boom->GameObject::AddComponent(sprite_boom);
    game->getStageState()->AddObject(boom);
    StageState* stageState = (StageState*)game->getStageState();
    stageState->nAliens--;
    this->associated->RequestDelete();
  }

  this->associated->angleDeg++;
  if(this->associated->angleDeg>= 360)
    this->associated->angleDeg = this->associated->angleDeg - 360;
}

void Alien::Render(){

}

bool Alien::Is (std::string type){
  if(type == "Alien"){
    return true;
  }
  else
    return false;
}



void Alien::NotifyCollision(GameObject& other){
	if(other.GetComponent("PenguinBody") != nullptr){
    //std::cout << "alien hit penguim " << std::endl;
  }
  if(other.GetComponent("Bullet") != nullptr){
    Bullet* bullet = (Bullet*)other.GetComponent("Bullet");
    if(bullet->targetsPlayer == true){
      this->hp = this->hp - 10;
    }
  }
}
