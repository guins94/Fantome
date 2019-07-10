#include"TeleportationOrb.h"

TeleportationOrb::TeleportationOrb(GameObject* associated,int teleportID){
  this->associated = associated;
  this->teleportID = teleportID;
  //Sprite* sprite = new Sprite(this->associated);
  //sprite->Open("assets/img/penguinface.png");
  //associated->GameObject::AddComponent(sprite);
  Sound* sound = new Sound(this->associated,"assets/SFX/fire.ogg");
  //sound->Play(1);
  this->fireSound = sound;
  Timer* timer = new Timer();
  this->yellowTimer = timer;
  Timer* timer1 = new Timer();
  this->restTimer = timer1;
  this->leftOrbPosition = Vec2(100,100);
  this->rightOrbPosition = Vec2(300,100);
}

TeleportationOrb::~TeleportationOrb(){

}

void TeleportationOrb::Start(){

}

void TeleportationOrb::Update(float dt){
  /*this->restTimer->Update(dt);

  if(this->restTimer->Get() >= 1){

  }*/

  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  if(this->teleportID == 1)
    std::cout << "orb -> "<< this->teleportID <<" State - >" << fantomeState->leftOrbState<<'\n';

  if(this->teleportID == 2)
    std::cout << "orb -> "<< this->teleportID <<" State - >" << fantomeState->rightOrbState<<'\n';

  if(fantomeState->leftOrbState == YELLOW && this->teleportID == 1){
    if(this->yellowTimer->Get() >= 5){
      fantomeState->leftOrbState = BLUE;
      this->yellowTimer->Restart();
    }
    this->yellowTimer->Update(dt);
  }

  if(fantomeState->rightOrbState == YELLOW && this->teleportID == 2){
    if(this->yellowTimer->Get() >= 5){
      fantomeState->rightOrbState = BLUE;
      this->yellowTimer->Restart();
    }
    this->yellowTimer->Update(dt);
  }

  if(fantomeState->leftOrbState == YELLOW && fantomeState->rightOrbState == YELLOW){
    fantomeState->leftOrbState = RED;
    fantomeState->rightOrbState = RED;
  }

  //float distanceLeftOrb = fantomeState->PlayerPosition.x - this->leftOrbPosition.x;
  //float distanceRightOrb = fantomeState->PlayerPosition.x - this->rightOrbPosition.x;
  //std::cout << "teleport id"<<this->teleportID<<" fantome"<< fantomeState->teleportID<< '\n';
  if(this->teleportID == fantomeState->teleportID && fantomeState->leftOrbState != RED){
    //if(this->restTimer->Get() >=3){
      GameObject* possession = new GameObject();
      possession->box.w = 30;
      possession->box.h = 30;
      possession->box.x = this->associated->box.x + 200;//respawnPosition.x;
      possession->box.y = this->associated->box.y;//respawnPosition.y;
      possession->GameObject::AddComponent(new Possession(possession,2));
      Collider* possession_collider = new Collider(possession);
      possession->GameObject::AddComponent(possession_collider);
      Game::GetInstance()->GetCurrentState()->AddObject(possession);
      fantomeState->isAlive = true;
      fantomeState->teleportID = 0;
      //game->GetCurrentState()->AddObject(minion_go)
    //}
  }
  //this->restTimer->Update(dt);

  if(fantomeState->leftOrbState == RED && this->switchPlaces == true){
    GameObject* possession = new GameObject();
    possession->box.w = 30;
    possession->box.h = 30;
    possession->box.x = 1300;//respawnPosition.x;
    possession->box.y = 500;//respawnPosition.y;
    possession->GameObject::AddComponent(new Possession(possession,2));
    Collider* possession_collider = new Collider(possession);
    possession->GameObject::AddComponent(possession_collider);
    fantomeState->AddObject(possession);
    fantomeState->isAlive = true;
  }
  this->switchPlaces = false;

}

void TeleportationOrb::Render(){

}

bool TeleportationOrb::Is (std::string type){
  return (type == "TeleportationOrb");
}



void TeleportationOrb::NotifyCollision(GameObject& other){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  if(other.GetComponent("Fantome") != nullptr){
    std::cout << "COLIDINDO COM FANTOME EM ORB" << '\n';
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
    //if(fantomeState->leftOrbState == BLUE||fantomeState->rightOrbState == BLUE){
      if(fantomeState->teleportID == 0){
        if(this->teleportID == 1)
          fantomeState->teleportID = 2;
        if(this->teleportID == 2)
          fantomeState->teleportID = 1;
      }
      this->switchPlaces = true;
  }
}
  if(other.GetComponent("Grave") != nullptr){
    if(fantomeState->leftOrbState == BLUE){
      fantomeState->leftOrbState = YELLOW;
      //fantomeState->rightOrbState = YELLOW; //PARA TESTE REMOVER DEPOIS ESSA LINHA
    }
  }
  if(other.GetComponent("Blade") != nullptr){
    if(fantomeState->rightOrbState == BLUE){
      fantomeState->rightOrbState = YELLOW;
    }
  }

}
