#include "ChainTail.h"

ChainTail::ChainTail(GameObject* associated, GameObject* chainHead, float angleRad) : Component(associated)
{
  this->associated = associated;
  this->playing = false;
  this->playingTimer = new Timer();
  this->possessionTimer = new Timer();

  if(chainHead)
  this->chainHead = (ChainHead*) chainHead->GetComponent("ChainHead");

  /* Adding Chain Head Sprite */
  Sprite* sprite = new Sprite(associated, 1, 0);
  sprite->Open("assets/img/penguinface.png");
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();
  this->associated->AddComponent(sprite);

  /* Adding Collider to the Chain Head */
  Collider* collider = new Collider(associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(collider);

  /* Calculating and setting ChainTail rotation */
  this->angleRad = angleRad;
  this->associated->angleDeg = GameData::RadToDeg(this->angleRad);
}

ChainTail::~ChainTail()
{

}

void ChainTail::SetChainRotation(float arc)
{
  if(this->angleRad != arc)
  {
    this->angleRad = arc;
    Start();
  }
}

float ChainTail::GetAngle()
{
  return this->angleRad;
}

void ChainTail::Update(float dt)
{
  /* Updating Possession Timer */
  this->possessionTimer->Update(dt);

  /* Setting Fantome Flag */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Getting InputManager Instance */
  InputManager* inputManager = InputManager::GetInstance();

  if(!this->playing)
  {
    this->playingTimer->Update(dt);
    return;
  }

  if(this->possessionTimer->Get() >= 1 && (!inputManager->KeyRelease(SDLK_SPACE)) && (!inputManager->KeyRelease(SDLK_w)))
  {
    GameObject* possession = new GameObject();
    possession->box.w = 30;
    possession->box.h = 30;
    possession->box.x = this->associated->box.x;
    possession->box.y = this->associated->box.y;
    possession->GameObject::AddComponent(new Possession(possession,2));
    Collider* possession_collider = new Collider(possession);
    possession->GameObject::AddComponent(possession_collider);
    fantomeState->AddObject(possession);
    this->playing = false;
    this->possessionTimer->Restart();
    this->playingTimer->Restart();
  }
}

void ChainTail::Render()
{

}

void ChainTail::Start()
{

}

bool ChainTail::Is(std::string type)
{
  if(type == "ChainTail"){
    return true;
  }
  else
    return false;
}

void ChainTail::NotifyCollision(GameObject& other)
{
  /* Getting InputManager Instance */
  InputManager* inputManager = InputManager::GetInstance();

  if(other.GetComponent("Fantome"))
  {
    if(!inputManager->KeyRelease(SDLK_SPACE))
    {
      if(this->playingTimer->Get() >= 1.5)
      {
        this->playing = true;
        this->playingTimer->Restart();
      }
      Camera::Follow(this->associated);
    }
  }

  /* Resolving ChainTail Collision With Chain */
  if(Chain* chain = (Chain*) other.GetComponent("Chain"))
  {
    /* If ChainTail Is Being Controlled by Fantome */
    if(this->playing)
    {
      /* If The Player Presses The A Key (Left) */
      if(!inputManager->KeyRelease(SDLK_a))
      {
        /* Decrements currentChain value */
        this->chainHead->currentChain--;

        /* If currentChain is a valid value for a chain */
        if(this->chainHead->currentChain >= 0 && this->chainHead->currentChain < this->chainHead->chainArray.size())
        {
          //Chain* chain = (Chain*) this->chainArray[i].get()->GetComponent("Chain");
          Sprite* sprite = (Sprite*) this->chainHead->chainArray[this->chainHead->currentChain].lock().get()->GetComponent("Sprite");
          sprite->SetScaleX(1.2); sprite->SetScaleY(1.2);

          this->playing = false;
          chain->isPlaying = true;
          Camera::Follow(&other);
        }
      }
    }
  }
}
