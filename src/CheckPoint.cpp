#include"CheckPoint.h"

CheckPoint::CheckPoint(GameObject* associated, int checkPointID)
{
  this->associated = associated;

  /* Initializing Variables */
  this->checkPointID = checkPointID;
  this->willActivate = false;

  /* Initializing Activation Sound */
  Sound* sound = new Sound(this->associated, "assets/SFX/checkpoint/checkPoint.ogg");
  this->fireSound = sound;

  /* Initializing Timer */
  this->restTimer.Restart();

  /* Initializing Sprite State */
  this->spriteState = SpriteState::DEACTIVATED;

  /* Initializing CheckPoint Sprite & Adding Collider */
  this->checkPointSprite = new Sprite(this->associated, "assets/img/checkpoint/checkPoint.png", 21, 0.1, 0);
  this->checkPointSprite->SetFrame(19);
  this->checkPointSprite->FreezeFrame(20);
  //TODO: fix the need to do the next two lines
  this->associated->box.w = this->checkPointSprite->GetHeight();
  this->associated->box.h = this->checkPointSprite->GetWidth();
  this->associated->AddComponent(this->checkPointSprite);

  Collider* checkPointCollider = new Collider(this->associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(checkPointCollider);
}

CheckPoint::~CheckPoint()
{

}

void CheckPoint::Start()
{

}

void CheckPoint::Update(float dt)
{
  /* Retrieving Fantome State Instance */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  SpriteState lastSpriteState = this->spriteState;

  std::cout << "CID: " << fantomeState->checkPointID << '\n';

  if(this->willActivate)
    this->spriteState = SpriteState::ACTIVATED;

  if(fantomeState->checkPointID != this->checkPointID)
    this->spriteState = SpriteState::DEACTIVATED;

  float distanceFantome = fantomeState->PlayerPosition.x - this->associated->box.x;
  if(fantomeState->isAlive == false && this->checkPointID == fantomeState->checkPointID){
    GameObject* possession = new GameObject();
    possession->box.w = 30;
    possession->box.h = 30;
    possession->box.x = this->associated->box.x;//respawnPosition.x;
    possession->box.y = this->associated->box.y;//respawnPosition.y;
    possession->GameObject::AddComponent(new Possession(possession,2));
    Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
    possession->GameObject::AddComponent(possession_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(possession);
    fantomeState->isAlive = true;
    //game->GetCurrentState()->AddObject(minion_go)
  }
  std::cout << "CP SS: " << this->spriteState << '\n';
  /* Updating CheckPoint Sprite */
  switch(this->spriteState)
  {
    case SpriteState::DEACTIVATED:
      if(this->spriteState != lastSpriteState)
      {
        this->checkPointSprite->Open("assets/img/checkpoint/checkPoint.png");
        this->checkPointSprite->SetFrameCount(21);
        this->checkPointSprite->SetFrameTime(0.1);
        this->checkPointSprite->ResetFreeze();
        this->checkPointSprite->SetFrame(19);
        this->checkPointSprite->FreezeFrame(20);
      }
      break;
    case SpriteState::ACTIVATED:
      if(this->spriteState != lastSpriteState)
      {
        this->checkPointSprite->Open("assets/img/checkpoint/checkPoint.png");
        this->checkPointSprite->SetFrameCount(21);
        this->checkPointSprite->SetFrameTime(0.05);
        this->checkPointSprite->ResetFreeze();
        this->checkPointSprite->SetFrame(0);
      }
      break;
  }

}

void CheckPoint::Render()
{

}

bool CheckPoint::Is (std::string type)
{
  return (type == "CheckPoint");
}

void CheckPoint::NotifyCollision(GameObject& other)
{
  /* Retrieving InputManager and Fantome State Instances */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  InputManager* inputManager = InputManager::GetInstance();

  if(other.GetComponent("Fantome"))
  {
    fantomeState->checkPointID = this->checkPointID;
    if(!this->willActivate)
      this->fireSound->Play(1);
    this->willActivate = true;
  }
}
