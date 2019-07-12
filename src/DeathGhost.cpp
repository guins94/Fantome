#include "DeathGhost.h"

DeathGhost::DeathGhost(GameObject* associated, int direction)
{
  /* Creating Link Between DeathGhost Class and its GameObject */
  this->associated = associated;

  /* Initializing Control Flags */
  this->isFantomeInSight = false;

  /* Adding DeathGhost Standing Animation Sprite */
  //this->deathGhostSprite = new Sprite(this->associated, "assets/img/bg character.png", 1, 1, 0);
  this->deathGhostSprite = new Sprite(this->associated, "assets/img/deathghost/standingDeathGhost.png", 10, 0.1, 0);
  this->associated->AddComponent(this->deathGhostSprite);
  this->associated->box.w = this->deathGhostSprite->GetHeight();
  this->associated->box.h = this->deathGhostSprite->GetWidth();

  /* Initializing Variables */
  this->spawnGhost = Vec2(associated->box.x, associated->box.y);
  this->restTimer.Restart();
  //this->blade.Open("assets/SFX/blade.ogg");

  /* Initializing DeathGhost Sprite State */
  this->spriteState = SpriteState::STANDING;

  /* Defining Death Ghost Facing Direction */
  switch(direction)
  {
    case 0:
      break;
    case 1:
      break;
  }
}

DeathGhost::~DeathGhost()
{

}

bool DeathGhost::IsFantomeRight()
{
  /* Retrieving Fantome State */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Calculating Fantome Distance */
  float distanceFromFantome = fantomeState->PlayerPosition.x - this->associated->box.x;

  /* If Distance is positive, Fantome is in the Right */
  /* If Distance is positive, Fantome is in the Left */
  if(distanceFromFantome >= 0)
    return true;
  else
    return false;
}

void DeathGhost::Start()
{

}

void DeathGhost::Update(float dt)
{
  /* Retrieving Fantome State */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  bool hasDeathGhostMoved = false;
  SpriteState lastSpriteState = this->spriteState;

  /* Calculating Distance Between Fantome and DeathGhost */
  float distanceFromFantome = fantomeState->PlayerPosition.x - this->associated->box.x;

  std::cout << "DFF: " << distanceFromFantome << '\n';

  if(IsFantomeRight())
  {
    if(fabs(distanceFromFantome) <= DEATH_GHOST_PRESENCE || this->isFantomeInSight)
    {
      /* Moving DeathGhost Right According to its Speed */
      this->associated->box.x = this->associated->box.x + dt * GameData::DeathGhostSpeed.x;

      /* Updating DeathGhost State to FOLLOWING */
      this->spriteState = SpriteState::FOLLOWING;

      /* Disable DeathGhost Sprite Flip */
      this->deathGhostSprite->DisableFlip();

      hasDeathGhostMoved = true;

      /* If Fantome is Within Attack Range */
      if(fabs(distanceFromFantome) <= DEATH_GHOST_ATTACK_RANGE)
      {
        this->restTimer.Update(dt);
      }
    }
  }
  else
  {
    if(fabs(distanceFromFantome) <= DEATH_GHOST_PRESENCE || this->isFantomeInSight)
    {
      /* Moving DeathGhost Left According to its Speed */
      this->associated->box.x = this->associated->box.x - dt * GameData::DeathGhostSpeed.x;

      /* Updating DeathGhost State to FOLLOWING */
      this->spriteState = SpriteState::FOLLOWING;

      /* Enable DeathGhost Sprite Flip */
      this->deathGhostSprite->EnableFlip();

      hasDeathGhostMoved = true;

      /* If Fantome is Within Attack Range */
      if(fabs(distanceFromFantome) <= DEATH_GHOST_ATTACK_RANGE)
      {
        this->restTimer.Update(dt);
      }
    }
  }

  /* If Death Ghost Has Not Moved, Death Ghost Goes Back to The Spawn Point */
  if(!hasDeathGhostMoved)
  {
    /* Calculating Distance Between Death Ghost and The Spawn Point */
    float distanceFromGuardPoint = this->spawnGhost.x - this->associated->box.x;

    if(fabs(distanceFromGuardPoint) >= 10)
    {
      if(distanceFromGuardPoint >= 0)
      {
        this->associated->box.x = this->associated->box.x + dt * GameData::DeathGhostSpeed.x;
        this->spriteState = SpriteState::FOLLOWING;

        /* Disable DeathGhost Sprite Flip */
        this->deathGhostSprite->DisableFlip();

        hasDeathGhostMoved = true;
      }
      else
      {
        this->associated->box.x = this->associated->box.x - dt * GameData::DeathGhostSpeed.x;
        this->spriteState = SpriteState::FOLLOWING;

        /* Enable DeathGhost Sprite Flip */
        this->deathGhostSprite->EnableFlip();

        hasDeathGhostMoved = true;
      }
    }
    else
    {
      /* If Death Ghost is Close Enough, Make its Position the Same as The GuardPoint */
      this->associated->box.x = this->spawnGhost.x;
      this->associated->box.y = this->spawnGhost.y;

      /* Updating DeathGhost State to STANDING */
      this->spriteState = SpriteState::STANDING;

      /* Disable DeathGhost Sprite Flip */
      this->deathGhostSprite->DisableFlip();
    }
  }

  switch(this->spriteState)
  {
    case SpriteState::STANDING:
      if(this->spriteState != lastSpriteState)
      {
        //TODO
      }
      break;
    case SpriteState::FOLLOWING:
      if(this->spriteState != lastSpriteState)
      {
        //TODO'
      }
      break;
  }
}

void DeathGhost::GhostAttack()
{
  if(this->restTimer.Get() >= 2){
    //this->blade->Play(1);
    GameObject* Attack = new GameObject();

    Attack->box.x = this->associated->box.x + 200;
    Attack->box.y = this->associated->box.y + 70;
    Attack->box.w = 100;
    Attack->box.h = 40;
    Sprite* sprite = new Sprite(Attack);
    sprite->Open("assets/img/penguin/penguin.png");
    Attack->GameObject::AddComponent(sprite);

    Blade* blade_component = new Blade(Attack,100,100,1);
    Attack->GameObject::AddComponent(blade_component);

    Collider* holyLight_collider = new Collider(Attack, Vec2(1,1), Vec2(0,0));
    //Vec2 offset = Vec2(200,-50);
    //holyLight_collider->SetOffset(offset);
    Attack->GameObject::AddComponent(holyLight_collider);
    Game::GetInstance()->GetCurrentState()->AddObject(Attack);

    std::cout << "ATAAAAAAAAAAAAAAQUE" << '\n';
    this->restTimer.Restart();
  }
}

void DeathGhost::Render()
{

}

bool DeathGhost::Is (std::string type)
{
  return (type == "DeathGhost");
}

void DeathGhost::NotifyCollision(GameObject& other)
{

}
