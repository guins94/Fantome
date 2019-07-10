#include "BoneFrog.h"

BoneFrog::BoneFrog(GameObject* associated)
{
  this->associated = associated;

  this->isPlaying = false;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->possessionTimer = new Timer();
  this->fallingSpeed = GRAVITY_MIN_LIMIT;

  /* Loading Bone Frog Sounds */
  this->frogJump = new Sound(this->associated, "assets/SFX/frogjump.ogg");
  this->frogLand = new Sound(this->associated, "assets/SFX/frogland.ogg");
}

void BoneFrog::Update(float dt)
{
  /* Retrieving Fantome State and InputManager */
  InputManager* inputManager = InputManager::GetInstance();
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Updating Possession Timer */
  this->possessionTimer->Update(dt);

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
  }
  else
  {
    /* Resetting Gravity to Minimum Speed */
    this->fallingSpeed = GRAVITY_MIN_LIMIT;
  }
  this->associated->futureBox = auxBox;

  /* Controls for BoneFrog */
  if(this->isPlaying)
  {
    /* Updating Rest Timer */
    this->restTimer->Update(dt);

    /* Calculating BoneFrog's Future X Position */
    if(!inputManager->KeyRelease(SDLK_a))
    {
      this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::boneFrogSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;
    }

    if(!inputManager->KeyRelease(SDLK_d))
    {
      this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::boneFrogSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
        this->associated->box.x = this->associated->futureBox.x;
      this->associated->futureBox = auxBox;
    }

    this->associated->futureBox = this->associated->box;

    if(!inputManager->KeyRelease(SDLK_w) && this->restTimer->Get() >= BONEFROG_JUMP_COOLDOWN)
    {
      this->frogJump->Play(1);
      this->fallingSpeed = -BONEFROG_JUMP_SPEED;
      this->restTimer->Restart();
    }

    if(this->possessionTimer->Get() >= 1 && (!inputManager->KeyRelease(SDLK_SPACE)) && (!inputManager->KeyRelease(SDLK_w)))
    {
      GameObject* possession = new GameObject();
      possession->box.w = 30;
      possession->box.h = 30;
      possession->box.x = this->associated->box.x;
      possession->box.y = this->associated->box.y;
      possession->GameObject::AddComponent(new Possession(possession,2));
      Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
      possession->GameObject::AddComponent(possession_collider);
      Game::GetInstance()->GetCurrentState()->AddObject(possession);
      this->isPlaying = false;
      this->possessionTimer->Restart();
      this->associated->RequestDelete();
    }
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

  /* Resolving BoneFrog Collision with Fantome */
	if(this->possessionTimer->Get() >= 1 && other.GetComponent("Fantome"))
  {
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->isPlaying = true;
      Camera::Follow(this->associated);
    }
  }
}

void BoneFrog::Start(){

}
