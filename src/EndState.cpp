#include "EndState.h"

EndState::EndState()
{
  /* Retrieving Fantome State Instance */
  FantomeState* fantomeState = (FantomeState*) Game::GetInstance()->GetCurrentState();

  GameObject* titleGo = new GameObject();
  titleGo->box.w = 0;
  titleGo->box.h = 0;
  titleGo->box.x = 0;
  titleGo->box.y = 0;

  Sprite* titleSprite = nullptr;

  /* Initializing Sprite and Back Ground Music according to Number of SoulStones Collected */
  switch(fantomeState->nSoulStone)
  {
    case 0:

      titleSprite = new Sprite(titleGo, "assets/img/title/gameOver.jpg", 16, 0.1, 0);
      titleGo->AddComponent(titleSprite);
      this->backgroundMusic.Open("assets/audio/title/endingSoundTrack.ogg");
      this->backgroundMusic.Play(-1);
      break;
    case 1:
      titleSprite = new Sprite(titleGo, "assets/img/title/bestEnding.jpg", 16, 0.1, 0);
      titleGo->AddComponent(titleSprite);
      this->backgroundMusic.Open("assets/audio/title/endingSoundTrack.ogg");
      this->backgroundMusic.Play(-1);
      break;
    case 2:
      titleSprite = new Sprite(titleGo, "assets/img/title/bestEnding.jpg", 16, 0.1, 0);
      titleGo->AddComponent(titleSprite);
      this->backgroundMusic.Open("assets/audio/title/endingSoundTrack.ogg");
      this->backgroundMusic.Play(-1);
      break;
    case 3:
      titleSprite = new Sprite(titleGo, "assets/img/title/bestEnding.jpg", 16, 0.1, 0);
      titleGo->AddComponent(titleSprite);
      this->backgroundMusic.Open("assets/audio/title/endingSoundTrack.ogg");
      this->backgroundMusic.Play(-1);
      break;
  }

  /* Adding Camera Follower */
  CameraFollower* cameraFollower = new CameraFollower(titleGo);
  titleGo->AddComponent(cameraFollower);

  /* Adding GameObject to State */
  this->objectArray.emplace_back(titleGo);
  std::cout << "OPA" << '\n';
}


EndState::~EndState()
{
	this->objectArray.clear();
}

void EndState::LoadAssets()
{

}

void EndState::Render()
{
  int i;
  for(i = 0; i <= this->objectArray.size() - 1; i++)
  {
    objectArray[i]->Render();
  }
}

void EndState::Start()
{
  int i;
  for(i = 0; i <= this->objectArray.size() - 1; i++)
  {
    this->objectArray[i]->Start();
  }
  this->started = true;
}

void EndState::Update()
{
  /* Retrieving Input Manager & Game Instances */
  InputManager* inputManager = InputManager::GetInstance();
  Game* game = Game::GetInstance();

  /* If Space Is Pressed, Load Fantome State */
  /*if(!inputManager->KeyRelease(SDLK_SPACE))
  {
    this->popRequested = true;
    game->Push(new FantomeState());
  }*/

  /* If Esc or Window 'X' Is Pressed, End The Game */
  if(!inputManager->KeyRelease(ESCAPE_KEY) || inputManager->QuitRequested() || !inputManager->KeyRelease(SDLK_SPACE))
    this->quitRequested = true;

  /* Calling All Updates */
  int i;
  for(i = 0; i < this->objectArray.size(); i++){
    this->objectArray[i]->Update(game->GetDeltaTime());
  }
}

void EndState::Pause()
{

}

void EndState::Resume()
{

}

std::weak_ptr<GameObject> EndState::AddObject(GameObject* go)
{

}

std::weak_ptr<GameObject> EndState::GetObjectPtr(GameObject* go)
{

}
