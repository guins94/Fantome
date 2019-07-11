#include "Game.h"

Game* Game::instance = NULL;

Game::Game(const char* title, int height, int width)
{
    this->height = height;
    this->width = width;

    if(!instance)
      instance = this;


    /* Initializing All Libraries  */
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Unable to initialize SDL_Init: %s", SDL_GetError());
        exit(-1);
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
      SDL_Log("Unable to initialize SDL_IMG: %s", SDL_GetError());
      exit(-1);
    }

    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG) == 0)
    {
      SDL_Log("Unable to initialize SDL Mix_Init: %s", SDL_GetError());
      exit(-1);
    }

    if(TTF_Init() != 0)
    {
    SDL_Log("Unable to initialize SDL TTF_Init(): %s", SDL_GetError());
    exit(-1);
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
      SDL_Log("Unable to initialize SDL OpenAudio: %s", SDL_GetError());
      exit(-1);
    }
    Mix_AllocateChannels(32);

    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(!this->window)
    {
    SDL_Log("Unable to initialize window: %s", SDL_GetError());
    exit(-1);
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!this->renderer)
    {
      SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
      exit(-1);
    }

    /* Initializing Stored State */
    this->storedState = nullptr;

    /* Seeding Rand Function*/
    srand(time(NULL));

    /* Calculating Delta Time */
    float lastFrame = this->frameStart;
    this->frameStart = SDL_GetTicks();
    this->dt = (float) (this->frameStart - lastFrame)/1000;
}


Game::~Game()
{
    if(!instance)
      instance = this;

    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}


Game* Game::GetInstance()
{
    if(!instance)
      instance = new Game("Fantome", 600, 1024);

    return instance;
}

State* Game::GetCurrentState()
{
  if(!this->stateStack.empty())
    return this->stateStack.top().get();
  else
    return nullptr;
}

void Game::Run()
{
  /* Retrieving Input Manager Instance */
  InputManager* inputManager = InputManager::GetInstance();

  while(1)
  {
    /* If There Is a Stored State */
    if(this->storedState)
    {
      /* Pausing the Current State */
      if(!this->stateStack.empty()) this->stateStack.top()->Pause();

      /* Pushing New State and Starting It */
      stateStack.emplace(this->storedState);
      GetCurrentState()->Start();

      /* Resetting Stored State */
      this->storedState = nullptr;
    }

    /* If The Game Wants to Pop */
    if(GetCurrentState()->GetPopRequested())
    {
      /* Popping Current Stage */
      std::unique_ptr<State> popState(std::move(this->stateStack.top()));
      this->stateStack.pop();
      /* If State Stack is Empty, Load A New Title Stage */
      /* If Not Empty, Resume State Below It */
      if(this->stateStack.empty())
      {
        if(!this->storedState)
          Push(new TitleState());
      }
      else
      {
        GetCurrentState()->Resume();
      }
    }

    /* If The State Wants to Quit, End Game */
    if(GetCurrentState()->GetQuitRequested())
    {
      std::cout << "Quit Requested. Exiting." << '\n';
      break;
    }

    CalculateDeltaTime();
    inputManager->Update();
    GetCurrentState()->Update();
    GetCurrentState()->Render();
    SDL_RenderPresent(renderer);
    SDL_Delay(33);
  }
}

SDL_Renderer* Game::GetRenderer()
{
    return this->renderer;
}

void Game::CalculateDeltaTime()
{
  float lastFrame = this->frameStart;
  this->frameStart = SDL_GetTicks();
  this->dt = (float) (this->frameStart - lastFrame)/1000;
}

float Game::GetDeltaTime()
{
  return dt;
}

void Game::Push(State* state)
{
  this->storedState = state;
}

int main (int argc, char** argv)
{
    argv = argv;
    argc = argc;

    Game* instance = Game::GetInstance();
    instance->Push(new FantomeState());
    instance->Run();

    delete instance;

    return 0;
}
