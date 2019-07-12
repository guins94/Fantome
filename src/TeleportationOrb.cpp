#include"TeleportationOrb.h"

TeleportationOrb::TeleportationOrb(GameObject* associated, int teleportID)
{
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

  this->boneFrogSprite = new Sprite(this->associated, "assets/img/portais/portal2_spritesheet.png", 16, 0.1, 0);
  this->associated->AddComponent(this->boneFrogSprite);
  this->associated->box.w = this->boneFrogSprite->GetHeight();
  this->associated->box.h = this->boneFrogSprite->GetWidth();
}

TeleportationOrb::~TeleportationOrb()
{

}

void TeleportationOrb::Start()
{

}

void TeleportationOrb::Update(float dt)
{
  /*this->restTimer->Update(dt);

  if(this->restTimer->Get() >= 1){

  }*/

  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();




  //Sprite* blueSprite = new Sprite(particlesGo, "assets/img/portais/portal1_spritesheet.png", 16, 0.2, 0);
  //this->associated->AddComponent(blueSprite);

  if(this->teleportID == 1){
    switch(fantomeState->leftOrbState)
    {
      case 0:
          this->boneFrogSprite->Open("assets/img/portais/portal1_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
        break;
      case 1:
          this->boneFrogSprite->Open("assets/img/portais/portal2_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
        break;
      case 2:
          this->boneFrogSprite->Open("assets/img/portais/portal3_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
          //this->boneFrogSprite->FreezeFrame();
        break;
    }
  }
    //std::cout << "orb -> "<< this->teleportID <<" State - >" << fantomeState->leftOrbState<<'\n';

  if(this->teleportID == 2){
    switch(fantomeState->rightOrbState)
    {
      case 0:
          this->boneFrogSprite->Open("assets/img/portais/portal1_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
        break;
      case 1:
          this->boneFrogSprite->Open("assets/img/portais/portal2_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
        break;
      case 2:
          this->boneFrogSprite->Open("assets/img/portais/portal3_spritesheet.png");
          this->boneFrogSprite->SetFrameCount(16);
          this->boneFrogSprite->SetFrameTime(0.1);
          this->boneFrogSprite->ResetFreeze();
          //this->boneFrogSprite->FreezeFrame();
        break;
    }
  }
    //std::cout << "orb -> "<< this->teleportID <<" State - >" << fantomeState->rightOrbState<<'\n';

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
    Collider* possession_collider = new Collider(possession,Vec2(1,1), Vec2(0,0));
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
    possession->box.x = 6100;//respawnPosition.x;
    possession->box.y = 20;//respawnPosition.y;
    possession->GameObject::AddComponent(new Possession(possession,2));
    Collider* possession_collider = new Collider(possession,Vec2(1,1), Vec2(0,0));
    possession->GameObject::AddComponent(possession_collider);
    //fantomeState->AddObject(possession);
    fantomeState->isAlive = true;
  }
  this->switchPlaces = false;

}

void TeleportationOrb::Render()
{

}

bool TeleportationOrb::Is (std::string type)
{
  return (type == "TeleportationOrb");
}



void TeleportationOrb::NotifyCollision(GameObject& other)
{
  /* Retrieving Fantome State and Input Manager Instances */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  InputManager* inputManager = InputManager::GetInstance();

  if(other.GetComponent("Fantome"))
  {
    std::cout << "COLIDINDO COM FANTOME EM ORB" << '\n';
    if(!inputManager->KeyRelease(SDLK_SPACE))
    {
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

  if(other.GetComponent("Grave"))
  {
    if(fantomeState->leftOrbState == BLUE)
    {
      fantomeState->leftOrbState = YELLOW;
      //fantomeState->rightOrbState = YELLOW; //PARA TESTE REMOVER DEPOIS ESSA LINHA
    }
  }

  if(other.GetComponent("Blade"))
  {
    if(fantomeState->rightOrbState == BLUE)
    {
      fantomeState->rightOrbState = YELLOW;
    }
  }

}
