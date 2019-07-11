#include "TitleState.h"

TitleState::TitleState()
{
  /* Initializing Control Flags */
  this->willExit = false;

  this->titleGo = new GameObject();
  this->titleGo->box.w = 0;
  this->titleGo->box.h = 0;
  this->titleGo->box.x = 0;
  this->titleGo->box.y = 0;

  Sprite* titleSprite = new Sprite(this->titleGo, "assets/img/title/title.jpg", 16, 0.1, 0);
  this->titleGo->AddComponent(titleSprite);

  this->playOrExit = new Sprite(this->titleGo, "assets/img/title/playGlow.png", 7, 0.125, 0);
  this->titleGo->AddComponent(this->playOrExit);

  CameraFollower* cameraFollower = new CameraFollower(this->titleGo);
  this->titleGo->AddComponent(cameraFollower);

  /* Initializing Sprite State */
  spriteState = SpriteState::PLAY;

  this->objectArray.emplace_back(this->titleGo);

  /* Initializing Title Music */
  this->backgroundMusic.Open("assets/audio/title/menuSoundTrack.ogg");
  this->backgroundMusic.Play(-1);

  /* Initializing Timers */
  this->optionTimer.Restart();
  this->exitTimer.Restart();

  /* Initializing SFX */
  this->selectionSFX = new Sound(this->titleGo, "assets/SFX/title/selectionSFX.ogg");
  this->choiceSFX = new Sound(this->titleGo, "assets/SFX/title/choiceSFX.ogg");
}


TitleState::~TitleState()
{
	this->objectArray.clear();
}

void TitleState::LoadAssets()
{

}

void TitleState::Render()
{
  int i;
  for(i = 0; i <= this->objectArray.size() - 1; i++){
    this->objectArray[i]->Render();
  }
}

void TitleState::Start()
{
  int i;
  for(i = 0; i <= this->objectArray.size() -1; i++)
  {
    this->objectArray[i]->Start();
  }
  this->started = true;
}

void TitleState::Update()
{
  /* Retrieving Input Manager & Game Instances */
  InputManager* inputManager = InputManager::GetInstance();
  Game* game = Game::GetInstance();

  /* Storing Last SpriteState */
  SpriteState lastSpriteState = this->spriteState;

  /* Updating Option Timer */
  this->optionTimer.Update(Game::GetInstance()->GetDeltaTime());

  /* Updating Exit Timer if The Player Asked to Quit The Game */
  if(this->willExit)
    this->exitTimer.Update(Game::GetInstance()->GetDeltaTime());

  if(this->spriteState == SpriteState::EXIT && this->willExit)
  {
    if(this->exitTimer.Get() >= MENU_EXIT_TIME)
    {
      /* After a Certain Amount of Seconds, The Game Really Quits */
      if(this->exitTimer.Get() >= MENU_EXIT_TIME)
        this->quitRequested = true;
    }
  }
  else
  {
    if(this->exitTimer.Get() >= MENU_EXIT_TIME)
    {
      /* After a Certain Amount of Seconds, The Game Loads Fantome State */
      this->popRequested = true;
      game->Push(new FantomeState());
      std::cout << "Loading Game. Please Wait..." << '\n';
    }
  }

  /* If Space Is Pressed, Load Fantome State */
  if(!inputManager->KeyRelease(SPACE_KEY) && this->spriteState == SpriteState::PLAY)
  {
    /* Calling PlayExitAnimation() */
    if(!this->willExit)
      PlayExitAnimation();

    /* Playing Choice Sound */
    this->choiceSFX->Play(1);
  }

  /* If Esc Is Pressed, End The Game */
  if(inputManager->QuitRequested() || (!inputManager->KeyRelease(SPACE_KEY) &&
  this->spriteState == SpriteState::EXIT))
  {
    /* Calling PlayExitAnimation() */
    if(!this->willExit)
      PlayExitAnimation();

    /* Playing Choice Sound */
    this->choiceSFX->Play(1);
  }

  if(!inputManager->KeyRelease(SDLK_w) || !inputManager->KeyRelease(SDLK_s))
  {
    if(this->optionTimer.Get() >= MENU_OPTION_CHANGE_COOLDOWN)
    {
      if(this->spriteState == SpriteState::PLAY)
        this->spriteState = SpriteState::EXIT;
      else
        this->spriteState = SpriteState::PLAY;

      /* Restarting Option Timer */
      this->optionTimer.Restart();

      /* Playing Selection Sound */
      this->selectionSFX->Play(1);
    }
  }

  switch(this->spriteState)
  {
    case SpriteState::PLAY:
      if(this->spriteState != lastSpriteState)
      {
        this->playOrExit->Open("assets/img/title/playGlow.png");
      }
      break;
    case SpriteState::EXIT:
      if(this->spriteState != lastSpriteState)
      {
        this->playOrExit->Open("assets/img/title/exitGlow.png");
      }
      break;
   }

  /* Calling All Updates */
  int i;
  for(i = 0; i < this->objectArray.size(); i++){
    this->objectArray[i]->Update(game->GetDeltaTime());
  }
}

void TitleState::Pause()
{
  this->backgroundMusic.Stop(1500);
}

void TitleState::Resume()
{
  std::cout << "Hey, I Resumed!" << '\n';
  this->popRequested = false;
  this->quitRequested = false;
  this->willExit = false;
  this->spriteState = SpriteState::PLAY;
  this->playOrExit->Open("assets/img/title/playGlow.png");
  this->optionTimer.Restart();
  this->exitTimer.Restart();

  this->backgroundMusic.Open("assets/audio/title/menuSoundTrack.ogg");
  this->backgroundMusic.Play(-1);

  int i;
  for(i = 0; i < this->objectArray.size(); i++)
  {
    if(Sprite* sprite = (Sprite*) this->objectArray[i]->GetComponent("Sprite"))
    {
      this->objectArray[i]->box.w = 0;
      this->objectArray[i]->box.h = 0;
      this->objectArray[i]->box.x = 0;
      this->objectArray[i]->box.y = 0;
    }
  }
}

void TitleState::PlayExitAnimation()
{
  /* Setting Control Flag */
  this->willExit = true;

  /* Playing Fantome Letter Text Animation */
  GameObject* fantomeTextGo = new GameObject();
  this->fadeOut = new Sprite(this->titleGo, "assets/img/bg/fadeOut.png", 9, 0.1, 0);
  this->fadeOut->FreezeFrame(8);
  fantomeTextGo->AddComponent(this->fadeOut);
  this->fantomeGlow = new Sprite(this->titleGo, "assets/img/title/fantomeGlow.png", 16, 0.1, 0);
  //fantomeTextSprite->FreezeFrame(7);
  fantomeTextGo->AddComponent(this->fantomeGlow);
  CameraFollower* cameraFollower = new CameraFollower(fantomeTextGo);
  fantomeTextGo->AddComponent(cameraFollower);
  this->objectArray.emplace_back(fantomeTextGo);
}

std::weak_ptr<GameObject> TitleState::AddObject(GameObject* go)
{

}

std::weak_ptr<GameObject> TitleState::GetObjectPtr(GameObject* go)
{

}
