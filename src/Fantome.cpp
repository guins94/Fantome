#include "Fantome.h"

Fantome::Fantome(GameObject* associated)
{
  this->associated = associated;

  /* Initializing Falling Speed */
  this->fallingSpeed = GRAVITY_MIN_LIMIT;

  /* Standing Fantome */
  Sprite* sprite = new Sprite(this->associated, "assets/img/fantome/standingFantome.png", 6, 0.1, 0);
  this->associated->AddComponent(sprite);
  //TODO: fix the need to do the next two lines
  this->associated->box.w = sprite->GetHeight();
  this->associated->box.h = sprite->GetWidth();

  /* Initializng Fantome Timer */
  this->restTimer = new Timer();

  /* Initializing Future Box */
  this->associated->futureBox = this->associated->box;

  /* Initializing Fantome Sprite State */
  this->spriteState = SpriteState::STANDING;
}

Fantome::~Fantome()
{

}

/* Plays Fantome Death Sprite Sheet */
void Fantome::KillFantome()
{
  GameObject* fantomeDeathGo = new GameObject();
  Sprite* fantomeDeath = new Sprite(fantomeDeathGo, "assets/img/fantome/dyingFantome.png", 15, 0.1, 1.5);
  fantomeDeathGo->box.x = this->associated->box.x;
  fantomeDeathGo->box.y = this->associated->box.y;
  fantomeDeathGo->AddComponent(fantomeDeath);
  Game::GetInstance()->GetCurrentState()->AddObject(fantomeDeathGo);
}

void Fantome::Start()
{

}

void Fantome::Update(float dt)
{
  /* Retrieving Fantome State and InputManager */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();
  Rect auxBox = this->associated->futureBox;

  bool hasFantomeMoved = false;
  SpriteState lastSpriteState = this->spriteState;

  /* Retrieving Fantome Sprite */
  Sprite* sprite = (Sprite*) this->associated->GetComponent("Sprite");
  if(!sprite)
  {
    std::cout << "Fantome.cpp: Error retrieving fantome sprite. Exiting." << '\n';
    exit(-1);
  }

  /* Calculando eixo y da futura posição do Fantome */
  this->associated->futureBox.y = this->associated->futureBox.y + dt * this->fallingSpeed + FANTOME_FLOAT_HEIGHT;

  if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)) && !fantomeState->WillCollideWithGrave(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
  {
    /* Updating Position */
    this->associated->box.y += dt * this->fallingSpeed;

    /* Updating Gravity Acceleration */
    if(this->fallingSpeed <= GRAVITY_MAX_LIMIT - GRAVITY_ACC)
      this->fallingSpeed += GRAVITY_ACC;

    /* Setting Flag Indicating Fantome Has Moved within this Frame */
    hasFantomeMoved = true;
  }
  else
  {
    /* Setting Fantome Sprite State to Falling */
    this->spriteState = SpriteState::FALLING;

    /* Resetting Gravity to Minimum Speed */
    this->fallingSpeed = GRAVITY_MIN_LIMIT;
  }
  this->associated->futureBox = auxBox;

      std::cout << "Gravity: " << this->fallingSpeed << '\n';

  /* Calculando eixo x da futura posição do Fantome */
  InputManager* inputManager = InputManager::GetInstance();
  if(!inputManager->KeyRelease(SDLK_a))
  {
    /* If the player is going left, the sprite is flipped */
    sprite->EnableFlip();
    this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::fantomeSpeed.x;
    if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
      this->associated->box.x -= dt * GameData::fantomeSpeed.x;
    this->associated->futureBox = auxBox;
    this->spriteState = SpriteState::LEFT;
    hasFantomeMoved = true;
  }
  if(!inputManager->KeyRelease(SDLK_d))
  {
    /* If the player is going right, the sprite is back to normal */
    sprite->DisableFlip();
    this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::fantomeSpeed.x;
    if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)))
      this->associated->box.x += dt * GameData::fantomeSpeed.x;
    this->associated->futureBox = auxBox;
    this->spriteState = SpriteState::RIGHT;
    hasFantomeMoved = true;
  }

  if(!hasFantomeMoved)
  {
    this->spriteState = SpriteState::STANDING;
  }

  this->associated->futureBox.x = this->associated->box.x;
  this->associated->futureBox.y = this->associated->box.y + 150;
  this->associated->futureBox.h = 0.1;
  this->associated->futureBox.w = this->associated->box.w;

  /* Updating Fantome Sprite */
  switch(this->spriteState)
  {
    case SpriteState::STANDING:
      if(this->spriteState != lastSpriteState)
      {
        sprite->Open("assets/img/fantome/standingFantome.png");
        sprite->SetFrameCount(6);
        sprite->SetFrameTime(0.1);
      }
      break;
    case SpriteState::RIGHT:
      if(this->spriteState != lastSpriteState)
      {
        sprite->Open("assets/img/fantome/walkingFantome.png");
        sprite->SetFrameCount(6);
 		   sprite->SetFrameTime(0.1);
      }
      break;
    case SpriteState::LEFT:
      if(this->spriteState != lastSpriteState)
      {
        sprite->Open("assets/img/fantome/walkingFantome.png");
        sprite->SetFrameCount(6);
   		  sprite->SetFrameTime(0.1);
        sprite->EnableFlip();
      }
      break;
      //TODO
    case SpriteState::FALLING:
      /*if(this->spriteState != lastSpriteState)
      {
        sprite->Open("assets/img/fantome/fallingFantome.png");
        sprite->SetFrameCount(6);
   		  sprite->SetFrameTime(0.1);
        sprite->EnableFlip();
      }*/
      break;
  }
}

void Fantome::Render()
{

}


bool Fantome::Is(std::string type)
{
  return (type == "Fantome");
}

void Fantome::NotifyCollision(GameObject& other){
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  /* Resolving Fantome Collision With Ground */
	if(other.GetComponent("Collider") && other.GetComponent("Ground")){

  }

  if(other.GetComponent("Grave")){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_SPACE)){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      fantomeState->fantomeExist = false;
      this->associated->RequestDelete();

    }
  }

  if(other.GetComponent("BoneFrog")){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_SPACE)){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      fantomeState->fantomeExist = false;
      this->associated->RequestDelete();
    }
  }

  if(ChainHead* chainHead = (ChainHead*) other.GetComponent("ChainHead")){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_SPACE))
    {
      if(chainHead->GetPlayingTimer() >= PLAYING_TIMER_VALUE)
      {
        fantomeState->fantomeExist = false;
        this->associated->RequestDelete();
      }
    }
  }

  if(ChainTail* chainTail = (ChainTail*) other.GetComponent("ChainTail")){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_SPACE))
    {
      if(chainTail->GetPlayingTimer() >= PLAYING_TIMER_VALUE)
      {
        fantomeState->fantomeExist = false;
        this->associated->RequestDelete();
      }
    }
  }

  if(other.GetComponent("Blade"))
  {
      Camera::Follow(nullptr);
      fantomeState->fantomeExist = false;
      fantomeState->isAlive = false;

      /* Requesting Deletion */
      this->associated->RequestDelete();

      KillFantome();
  }

  if(other.GetComponent("Fire")){
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_SPACE)){
      //(Grave*)other.GetComponent("Grave")->playing == true;
      Camera::Follow(nullptr);
      fantomeState->fantomeExist = false;
      this->associated->RequestDelete();

    }
  }

  if(other.GetComponent("HolyLight")){
    Camera::Follow(nullptr);
    fantomeState->fantomeExist = false;
    fantomeState->isAlive = false;
    this->associated->RequestDelete();

    KillFantome();
  }
}
