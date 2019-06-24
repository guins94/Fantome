#include "ChainHead.h"

ChainHead::ChainHead(GameObject* associated, int nChains, float angleRad) : Component(associated)
{
  this->associated = associated;
  this->nChains = nChains;
  this->playing = false;
  this->playingTimer = new Timer();
  this->possessionTimer = new Timer();

  /* Adding Chain Head Sprite */
  Sprite* sprite = new Sprite(associated, 1, 0);
  sprite->Open("assets/img/penguinface.png");
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();
  this->associated->AddComponent(sprite);

  /* Adding Collider to the Chain Head */
  Collider* collider = new Collider(associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(collider);

  /* Calculating and setting chainHead rotation */
  this->angleRad = angleRad;
  this->associated->angleDeg = GameData::RadToDeg(this->angleRad);

  /* Storing Chain Width and Height */
  GameObject* goChain = new GameObject();
  Chain* chain = new Chain(goChain);
  this->chainWidth = goChain->box.w;
  this->chainHeight = goChain->box.h;

  /* Calculating lastChain position to create End Chain Module in the future */
  for(int i = 0; i < this->nChains; i++)
  {
    Rect auxBox;
    auxBox.x = this->associated->box.x + this->associated->box.w + this->chainWidth * (i);
    auxBox.y = this->associated->box.y + this->associated->box.h/2 - this->chainHeight/2;
    auxBox.w = this->chainWidth;
    auxBox.h = this->chainHeight;

    Vec2 associatedCenter = this->associated->box.GetCenter();
    Vec2 chainCenter = auxBox.GetCenter();
    Vec2 distance = chainCenter - associatedCenter;
    Vec2 result = distance.GetRotated(this->angleRad);
    this->lastChainPosition = Vec2(result.x + this->associated->box.x + auxBox.w, result.y + this->associated->box.y + this->associated->box.h/2);
  }
}

ChainHead::~ChainHead()
{
  /* Clearing chainArray */
  this->chainArray.clear();
}

void ChainHead::SetChainNumber(int nChains)
{
  if(this->nChains != nChains)
  {
    this->nChains = nChains;
    Start();
  }
}

void ChainHead::SetChainRotation(float arc)
{
  if(this->angleRad != arc)
  {
    this->angleRad = arc;
    Start();
  }
}

float ChainHead::GetChainWidth()
{
  return this->chainWidth;
}

float ChainHead::GetChainHeight()
{
  return this->chainHeight;
}

Vec2 ChainHead::GetLastChainPosition()
{
  return this->lastChainPosition;
}

float ChainHead::GetAngle()
{
  return this->angleRad;
}

void ChainHead::Update(float dt)
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

void ChainHead::Render()
{

}

void ChainHead::Start()
{
  /* Clearing chainArray */
  this->chainArray.clear();

  /* Getting current game state */
  State* state = Game::GetInstance()->GetCurrentState();

  for(int i = 0; i < this->nChains; i++)
  {
    /* Criando GameObject para a chain*/
    GameObject* goChain = new GameObject();

    /* Criando Chain */
    Chain* chain = new Chain(goChain);

    /* Setando as dimensões da Chain */
    goChain->box.x = this->associated->box.x + this->associated->box.w + goChain->box.w * (i);
    goChain->box.y = this->associated->box.y + this->associated->box.h/2 - goChain->box.h/2;

    /* Rotating Chain Box */
    Vec2 associatedCenter = this->associated->box.GetCenter();
    Vec2 chainCenter = goChain->box.GetCenter();
    Vec2 distance = chainCenter - associatedCenter;
    //std::cerr << "i: " << i << " X: " << distance.x << " Y: " << distance.y << '\n';
    Vec2 result = distance.GetRotated(this->angleRad);
    goChain->box.x = result.x + this->associated->box.x + goChain->box.w;
    goChain->box.y = result.y + this->associated->box.y + this->associated->box.h/2;

    /* Setting chain rotation */
    goChain->angleDeg = GameData::RadToDeg(this->angleRad);

    /* Adding Component and Object */
    goChain->AddComponent(chain);
    this->chainArray.push_back(state->AddObject(goChain));
  }
}

bool ChainHead::Is(std::string type)
{
  if(type == "ChainHead"){
    return true;
  }
  else
    return false;
}

void ChainHead::NotifyCollision(GameObject& other)
{
  /* Getting InputManager Instance */
  InputManager* inputManager = InputManager::GetInstance();

  /* Resolving ChainHead Collision With Fantome */
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
}
