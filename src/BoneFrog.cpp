#include "BoneFrog.h"

BoneFrog::BoneFrog(GameObject* associated)
{
  /* Creating Link Between BoneFrog Class & GameObject Class */
  this->associated = associated;

  /* Initializing VAriables & Control Flags */
  this->hp = BONEFROG_HITPOINTS;
  this->isPlaying = false;
  this->fallingSpeed = GRAVITY_MIN_LIMIT;

  /* Initializing BoneFrog Sprite State */
  this->spriteState = SpriteState::STANDING;

  /* Initializing Timers */
  this->restTimer.Restart();
  this->possessionTimer.Restart();

  /* Initializing BoneFrog Dying Sprite & Collider */
  this->boneFrogSprite = new Sprite(this->associated, "assets/img/bonefrog/possessed/dyingBoneFrog.png", 12, 0.1, 0);
  this->boneFrogSprite->SetFrame(11);
  this->associated->AddComponent(this->boneFrogSprite);
  this->associated->box.w = this->boneFrogSprite->GetHeight();
  this->associated->box.h = this->boneFrogSprite->GetWidth();

  Collider* collider = new Collider(this->associated, Vec2(1,0.25), Vec2(0,this->associated->box.w));
  this->associated->AddComponent(collider);

  /* Loading Bone Frog Sounds */
  this->frogJump = new Sound(this->associated, "assets/SFX/frogjump.ogg");
  this->frogLand = new Sound(this->associated, "assets/SFX/frogland.ogg");
}

void BoneFrog::Update(float dt)
{
  /* Retrieving Fantome State and InputManager */
  InputManager* inputManager = InputManager::GetInstance();
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Initializing Auxiliary Variables */
  /* Flags That Indicate BoneFrog Has Moved (or is falling) in this Frame */
  bool hasBoneFrogMoved = false;
  bool isFalling = false;
  SpriteState lastSpriteState = this->spriteState;

  /* Updating Possession Timer */
  this->possessionTimer.Update(dt);

  /* Initializing Auxiliary Variables */
  Rect auxBox = this->associated->futureBox;

  /* Calculating BoneFrog's Future Y Position */
  this->associated->futureBox.y = this->associated->futureBox.y + dt * this->fallingSpeed;

  /* If BoneFrog Won't Collide With the Ground, Update Its Position */
  if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
  {
    /* Updating Position */
    this->associated->box.y = this->associated->futureBox.y;

    /* Updating Gravity Acceleration */
    if(this->fallingSpeed <= GRAVITY_MAX_LIMIT - GRAVITY_ACC)
      this->fallingSpeed += GRAVITY_ACC;

    /* Setting Control Flags */
    hasBoneFrogMoved = true;
    isFalling = true;
  }
  else
  {
    /* Resetting Gravity to Minimum Speed */
    this->fallingSpeed = GRAVITY_MIN_LIMIT;

    /* Bone Frog is not Falling Anymore */
    isFalling = false;
  }
  this->associated->futureBox = auxBox;

  /* Controls for BoneFrog */
  if(this->isPlaying)
  {
    /* Updating Rest Timer */
    this->restTimer.Update(dt);

    /* Calculating BoneFrog's Future X Position */
    if(!inputManager->KeyRelease(SDLK_a))
    {
      this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::boneFrogSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;

      if(!isFalling)
        this->spriteState = SpriteState::WALKING;

      /* Enable BoneFrog Sprite Flip */
      this->boneFrogSprite->EnableFlip();

      hasBoneFrogMoved = true;
    }

    if(!inputManager->KeyRelease(SDLK_d))
    {
      this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::boneFrogSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;

      if(!isFalling)
        this->spriteState = SpriteState::WALKING;

      /* Disable BoneFrog Sprite Flip */
      this->boneFrogSprite->DisableFlip();

      hasBoneFrogMoved = true;
    }

    this->associated->futureBox = this->associated->box;

    if(!inputManager->KeyRelease(SDLK_w) && this->restTimer.Get() >= BONEFROG_JUMP_COOLDOWN)
    {
      this->frogJump->Play(1);
      this->fallingSpeed = -BONEFROG_JUMP_SPEED;
      this->restTimer.Restart();

      this->spriteState = SpriteState::JUMPING;

      hasBoneFrogMoved = true;
    }

    if(this->possessionTimer.Get() >= 1 && (!inputManager->KeyRelease(SDLK_SPACE)) &&
    (!inputManager->KeyRelease(SDLK_w)) && !isFalling)
    {
      GameObject* possession = new GameObject();
      possession->box.w = 30;
      possession->box.h = 30;
      possession->box.x = this->associated->box.x;
      possession->box.y = this->associated->box.y;
      possession->AddComponent(new Possession(possession,2));
      Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
      possession->AddComponent(possession_collider);
      Game::GetInstance()->GetCurrentState()->AddObject(possession);
      this->isPlaying = false;
      this->possessionTimer.Restart();
    }
  }

  /* If BoneFrog Has Not Moved, Its Sprite State is STANDING */
  if(!hasBoneFrogMoved)
    this->spriteState = SpriteState::STANDING;

  if(!this->isPlaying)
    this->spriteState = SpriteState::DEAD;

    std::cout << "BONEFROG SS: " << this->spriteState << '\n';

  /* Updating BoneFrog Sprite */
  switch(this->spriteState)
  {
    case SpriteState::STANDING:
      if(this->spriteState != lastSpriteState)
      {
        this->boneFrogSprite->Open("assets/img/bonefrog/possessed/standingBoneFrog.png");
        this->boneFrogSprite->SetFrameCount(12);
        this->boneFrogSprite->SetFrameTime(0.1);
        this->boneFrogSprite->ResetFreeze();
      }
      break;
    case SpriteState::WALKING:
      if(this->spriteState != lastSpriteState)
      {
        this->boneFrogSprite->Open("assets/img/bonefrog/possessed/walkingBoneFrog.png");
        this->boneFrogSprite->SetFrameCount(12);
 		    this->boneFrogSprite->SetFrameTime(0.05);
        this->boneFrogSprite->ResetFreeze();
      }
      break;
    case SpriteState::JUMPING:
      if(this->spriteState != lastSpriteState)
      {
        this->boneFrogSprite->Open("assets/img/bonefrog/possessed/jumpingBoneFrog.png");
        this->boneFrogSprite->SetFrameCount(12);
        this->boneFrogSprite->SetFrame(6);
   		  this->boneFrogSprite->SetFrameTime(0.05);
        this->boneFrogSprite->ResetFreeze();
        this->boneFrogSprite->FreezeFrame(11);
      }
      break;
    case SpriteState::FALLING:
      if(this->spriteState != lastSpriteState)
      {
        this->boneFrogSprite->Open("assets/img/bonefrog/wild/fallingWildBoneFrog.png");
        this->boneFrogSprite->SetFrameCount(12);
   		  this->boneFrogSprite->SetFrameTime(0.1);
        this->boneFrogSprite->ResetFreeze();
        this->boneFrogSprite->FreezeFrame(11);
      }
      break;
    case SpriteState::DEAD:
      if(this->spriteState != lastSpriteState && !this->isPlaying)
      {
        this->boneFrogSprite->Open("assets/img/bonefrog/possessed/dyingBoneFrog.png");
        this->boneFrogSprite->SetFrameCount(12);
   		  this->boneFrogSprite->SetFrameTime(0.1);
        this->boneFrogSprite->ResetFreeze();
        this->boneFrogSprite->FreezeFrame(11);
      }
      break;
  }

}

void BoneFrog::Render()
{

}

bool BoneFrog::Is(std::string type){
  return ("BoneFrog" == type);
}

void BoneFrog::NotifyCollision(GameObject& other)
{
  /* Retrieving InputManager and Fantome State Instances */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  InputManager* inputManager = InputManager::GetInstance();

  /* Resolving BoneFrog Collision with Fantome */
	if(this->possessionTimer.Get() >= 1 && other.GetComponent("Fantome"))
  {
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->isPlaying = true;
      Camera::Follow(this->associated);
    }
  }
}

void BoneFrog::Start(){

}
