#include "DeathGhostSight.h"

DeathGhostSight::DeathGhostSight(GameObject* associated, GameObject* deathGhost, float deathGhostWidth, float deathGhostHeight)
{
  /* Creating Link Between DeathGhostSight Class and its GameObject */
  this->associated = associated;

  /* Storing DeathGhost GameObject Pointer */
  this->deathGhost = deathGhost;

  /* Adding DeathGhostSight Collider */
  Collider* sightCollider = new Collider(this->associated, Vec2(1,1), Vec2(deathGhostWidth, 0));
  this->associated->box.h = deathGhostHeight;
  this->associated->box.w = DEATH_GHOST_VISION_RANGE;
  this->associated->AddComponent(sightCollider);
}

DeathGhostSight::~DeathGhostSight()
{

}

void DeathGhostSight::Start()
{

}

void DeathGhostSight::Update(float dt)
{
  /* Retrieving DeathGhost Instance */
  if(DeathGhost* deathGhostInstance = (DeathGhost*) this->deathGhost->GetComponent("DeathGhost"))
  {
    std::cout << "DG SS: " << deathGhostInstance->spriteState << '\n';
    if(deathGhostInstance->spriteState == DeathGhost::SpriteState::FOLLOWRIGHT ||
    deathGhostInstance->spriteState == DeathGhost::SpriteState::ATCKRIGHT)
    {
      /* Updating Death Ghost Sight according to Death Ghost Position */
      this->associated->box.x = this->deathGhost->box.x;
      this->associated->box.y = this->deathGhost->box.y;
    }

    if(deathGhostInstance->spriteState == DeathGhost::SpriteState::FOLLOWLEFT ||
    deathGhostInstance->spriteState == DeathGhost::SpriteState::ATCKLEFT)
    {
      if(Sprite* sprite = (Sprite*) this->deathGhost->GetComponent("Sprite"))
      {
        /* If DeathGhost is Flipped, Flip Death Ghost Sight */
        this->associated->box.x = this->deathGhost->box.x - sprite->GetWidth() - DEATH_GHOST_VISION_RANGE;
      }
      this->associated->box.y = this->deathGhost->box.y;
    }
  }
}

void DeathGhostSight::Render()
{

}

bool DeathGhostSight::Is (std::string type)
{
  return (type == "DeathGhostSight");
}



void DeathGhostSight::NotifyCollision(GameObject& other)
{
  /* Resolving DeathGhostSight Collision with Fantome */
	if(other.GetComponent("Fantome"))
  {
    if(DeathGhost* deathGhostInstance = (DeathGhost*) this->deathGhost->GetComponent("DeathGhost"))
    {
      if(deathGhostInstance->IsFantomeRight())
      {
        std::cout << "Fantome is Right" << '\n';
        deathGhostInstance->spriteState = DeathGhost::SpriteState::FOLLOWRIGHT;
      }
      else
      {
        std::cout << "Fantome is Left" << '\n';
        deathGhostInstance->spriteState = DeathGhost::SpriteState::FOLLOWLEFT;
      }
    }
  }

  /* Resolving DeathGhostSight Collision with Grave */
	if(other.GetComponent("Grave"))
  {
  }
}
