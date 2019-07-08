#include "TitleState.h"

TitleState::TitleState()
{
  GameObject* titleGo = new GameObject();
  titleGo->box.w = 0;
  titleGo->box.h = 0;
  titleGo->box.x = 0;
  titleGo->box.y = 0;

  Sprite* titleSprite = new Sprite(titleGo, "assets/img/penguin/win.jpg", 1, 0, 0);
  titleGo->AddComponent(titleSprite);

  CameraFollower* cameraFollower = new CameraFollower(titleGo);
  titleGo->AddComponent(cameraFollower);

  this->objectArray.emplace_back(titleGo);

  /* Initializing Title Music */
  //TODO
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

  /* If Space Is Pressed, Load Fantome State */
  if(!inputManager->KeyRelease(SPACE_KEY))
  {
    this->popRequested = true;
    game->Push(new FantomeState());
    std::cout << "Loading Game. Please Wait..." << '\n';
  }

  /* If Esc Is Pressed, End The Game */
  if(!inputManager->KeyRelease(ESCAPE_KEY) || inputManager->QuitRequested())
    this->quitRequested = true;

  /* Calling All Updates */
  int i;
  for(i = 0; i < this->objectArray.size(); i++){
    this->objectArray[i]->Update(game->GetDeltaTime());
  }
}

void TitleState::Pause()
{

}

void TitleState::Resume()
{
  std::cout << "Hey, I Resumed!" << '\n';
  this->popRequested = false;
  this->quitRequested = false;

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

std::weak_ptr<GameObject> TitleState::AddObject(GameObject* go)
{

}

std::weak_ptr<GameObject> TitleState::GetObjectPtr(GameObject* go)
{

}
