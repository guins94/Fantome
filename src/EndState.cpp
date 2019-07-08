#include "EndState.h"

EndState::EndState(){
  GameObject* titleGo = new GameObject();
  titleGo->box.w = 0;
  titleGo->box.h = 0;
  titleGo->box.x = 0;
  titleGo->box.y = 0;

  Sprite* titleSprite = new Sprite(titleGo, "assets/img/penguin/lose.jpg", 1, 0, 0);
  titleGo->AddComponent(titleSprite);
  this->objectArray.emplace_back(titleGo);

  /* Initializing End Music */
  //TODO
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
  if(!inputManager->KeyRelease(SDLK_SPACE))
  {
    this->popRequested = true;
    game->Push(new FantomeState());
  }

  /* If Esc Is Pressed, End The Game */
  if(!inputManager->KeyRelease(ESCAPE_KEY))
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
