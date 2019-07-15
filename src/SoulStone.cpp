#include"SoulStone.h"

SoulStone::SoulStone(GameObject* associated)
{
  /* Creating Link Between the SoulStone and its GameObject */
  this->associated = associated;

  /* Initializing SoulStone Variables */
  this->distanceFromFantome = 0;

  /* Adding Sound Effects for the SoulStone */
  this->nearbySound = new Sound(this->associated, "assets/SFX/soulstone/nearbySoulStone.ogg");

  /* Initializing SFX Timer */
  this->soundTimer.Restart();

  /* Adding SoulStone Sprite */
  Sprite* sprite = new Sprite(this->associated, "assets/img/soulstone/soulStone.png", 22, 0.1, 0);
  this->associated->AddComponent(sprite);
  //TODO: fix the need to do the next two lines
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();

  /* Adding SoulStone Sound */
  Collider* soulStoneCollider = new Collider(this->associated, Vec2(1,1), Vec2(0,0));
  this->associated->AddComponent(soulStoneCollider);
}

SoulStone::~SoulStone()
{

}

void SoulStone::Start()
{

}

void SoulStone::Update(float dt)
{
  /* Retrieving Fantome State */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Calculating Distance Between This Soulstone and Fantome */
  this->distanceFromFantome = fantomeState->PlayerPosition.x - this->associated->box.x;

  /* If Fantome Does Not Exist, Don't Do Anything */
  if(!fantomeState->fantomeExist) return;

  /* Updating Timer */
  this->soundTimer.Update(dt);

  /* If Fantome is Nearby, Play SoulStone Sound */
  if(fabs(this->distanceFromFantome) <= NEARBY_SOULSTONE_DISTANCE)
  {
    if(this->soundTimer.Get() >= SOULSTONE_SOUND_LOOP)
    {
      this->nearbySound->Play(1);
      this->soundTimer.Restart();
    }
  }
  else
  {
    this->nearbySound->Stop();
  }
}

void SoulStone::Render()
{

}

bool SoulStone::Is (std::string type)
{
  return (type == "SoulStone");
}

void SoulStone::NotifyCollision(GameObject& other)
{
  /* Retrieving Fantome & InputManager Instances */
  InputManager* inputManager = InputManager::GetInstance();
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Resolving Collision Between Fantome and this Soulstone */
  if(other.GetComponent("Fantome") != nullptr)
  {
    std::cout << "SOULSTONE\n\n\n" << '\n';
    /* If Fantome Collects this SoulStone, it Disappears */
    if(!inputManager->KeyRelease(SDLK_SPACE))
    {
      fantomeState->nSoulStone += 1;
      this->associated->RequestDelete();
    }
  }
}
