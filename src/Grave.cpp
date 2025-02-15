#include "Grave.h"

Grave::Grave(GameObject* associated)
{
  this->associated = associated;

  this->spawnGrave = Vec2(this->associated->box.x,this->associated->box.y);
  this->falling = true;
  this->playing = false;
  Timer* timer = new Timer();
  this->restTimer = timer;
  this->possessionTimer = new Timer();
  Sound* sound = new Sound(this->associated,"assets/SFX/breakbox.ogg");
  this->breakBox = sound;
  Sound* sound2 = new Sound(this->associated,"assets/SFX/arrastabox.ogg");
  this->arrastaBox = sound2;

  this->graveSprite = new Sprite(this->associated);
  this->graveSprite->Open("assets/img/grave/graveSprite.png");
  this->associated->AddComponent(this->graveSprite);
  this->associated->box.w = 135;
  this->associated->box.h = 135;
}

Grave::~Grave()
{

}

void Grave::Start()
{

}

void Grave::Update(float dt)
{
  this->possessionTimer->Update(dt);
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  Rect auxBox = this->associated->futureBox;

  /* Calculando eixo y da futura posição do Fantome */
  this->associated->futureBox.y = this->associated->futureBox.y + dt * GameData::fantomeSpeed.y;
  if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg)) && !fantomeState->WillCollideWithGrave(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg))){
      this->associated->box.y += dt * GameData::fantomeSpeed.y;
      this->speed.y = this->speed.y + dt * GameData::fantomeSpeed.y;
      //std::cout << "Grave speed"<< this->speed.y << '\n';
  }else{
  /* Implementação da caixa quebrando ao coliddir com chão */
    if(this->speed.y>=200){
      RespawnGrave();
      //this->associated->RequestDelete();
    }
      this->speed.y = 0;
  }

  this->associated->futureBox = auxBox;

  /* Calculando eixo x da futura posição do Fantome */

  if(this->playing){
    this->restTimer->Update(dt);
    InputManager* inputManager = InputManager::GetInstance();
    if(!inputManager->KeyRelease(SDLK_a)){
      this->associated->futureBox.x = this->associated->futureBox.x - dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg))){
        this->spriteState = MOVING;
        this->associated->box.x = this->associated->futureBox.x;
        if(this->restTimer->Get() >= 1){
          this->arrastaBox->Play(1);
          this->restTimer->Restart();
        }

      }
      this->associated->futureBox = auxBox;
    }
    if(!inputManager->KeyRelease(SDLK_d)){
      this->associated->futureBox.x = this->associated->futureBox.x + dt * GameData::fantomeSpeed.x;
      if(!fantomeState->WillCollideWithGround(this->associated->futureBox, GameData::DegToRad(this->associated->angleDeg))){
        this->spriteState = MOVING;
        this->associated->box.x = this->associated->futureBox.x;
        if(this->restTimer->Get() >= 1){
          this->arrastaBox->Play(1);
          this->restTimer->Restart();
        }
      }
      this->associated->futureBox = auxBox;
    }

    if(this->possessionTimer->Get() >= 1 && (inputManager->KeyRelease(SDLK_SPACE) == false) && (inputManager->KeyRelease(SDLK_w) == false)){

      GameObject* possession = new GameObject();
      possession->box.w = 30;
      possession->box.h = 30;
      possession->box.x = this->associated->box.x;
      possession->box.y = this->associated->box.y;
      possession->GameObject::AddComponent(new Possession(possession,2));
      Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
      possession->GameObject::AddComponent(possession_collider);
      Game::GetInstance()->GetCurrentState()->AddObject(possession);
      //game->GetCurrentState()->AddObject(minion_go)
      this->playing = false;
      this->possessionTimer->Restart();
    }
  }
  this->associated->futureBox.x = this->associated->box.x;
  this->associated->futureBox.y = this->associated->box.y + 150;
  this->associated->futureBox.h = 0.1;
  this->associated->futureBox.w = this->associated->box.w;
/*
  switch(this->spriteState)
  {
    case SpriteState::STOPPED:
        this->graveSprite->Open("assets/img/caixa/ss_caixa.png");
        this->graveSprite->SetFrameCount(7);
        this->graveSprite->SetFrameTime(0.1);
        this->graveSprite->ResetFreeze();
        this->graveSprite->FreezeFrame(0);
      break;
    case SpriteState::MOVING:
        this->graveSprite->Open("assets/img/caixa/ss_caixa.png");
        this->graveSprite->SetFrameCount(7);
        this->graveSprite->SetFrameTime(0.1);
        this->graveSprite->ResetFreeze();
      break;
  }
*/
  this->spriteState = STOPPED;

}

void Grave::Render()
{

}

bool Grave::Is (std::string type)
{
  return ("Grave" == type);
}

void Grave::NotifyCollision(GameObject& other)
{
	if(this->possessionTimer->Get() >= 1 && other.GetComponent("Fantome") != nullptr){
    InputManager* inputManager = InputManager::GetInstance();
    if(inputManager->KeyRelease(SDLK_SPACE) == false){
      this->playing = true;
      Camera::Follow(this->associated);
    }
  }
}

void Grave::RespawnGrave()
{
  this->breakBox->Play(1);
  //std::cout << "RespawnGrave" << '\n';
  GameObject* possession = new GameObject();
  possession->box.w = 30;
  possession->box.h = 30;
  possession->box.x = this->associated->box.x;
  possession->box.y = this->associated->box.y;
  possession->GameObject::AddComponent(new Possession(possession,2));
  Collider* possession_collider = new Collider(possession, Vec2(1,1), Vec2(0,0));
  possession->GameObject::AddComponent(possession_collider);
  Game::GetInstance()->GetCurrentState()->AddObject(possession);
  Camera::Follow(possession);
  //game->GetCurrentState()->AddObject(minion_go)
  this->playing = false;
  this->possessionTimer->Restart();
  this->associated->box.x = this->spawnGrave.x;
  this->associated->box.y = this->spawnGrave.y;
}
