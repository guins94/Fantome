#include "Game.h"

Game* Game::instance = NULL;

Game::Game(const char* title,int height, int width){

    this->height = height;
    this->width = width;

    if (instance == NULL)
        instance = this;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024);
    Mix_AllocateChannels(32);
    TTF_Init();


    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window;

    window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,0);
    this->window = window;
    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
    }


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    this->storedState = nullptr;
    this->dt = 0;
    this->frameStart = SDL_GetTicks();
    // The window is open: could enter program loop here (see SDL_PollEvent())

}


Game::~Game(){
    if (instance == NULL)
        instance = this;
    //delete Game::GetCurrentState();

    TTF_Quit();
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();

}


Game* Game::GetInstance(){
    if(instance == NULL){
       instance = new Game("Fantome",600, 1024);
    }

    return instance;
}

State* Game::GetCurrentState(){
  return this->stateStack.top().get();
}

void Game::Run(){
  InputManager* inputManager = InputManager::GetInstance();
  stateStack.emplace(this->storedState);
  Game::GetCurrentState()->Start();
  while(inputManager->QuitRequested() != true){
    //std::cout << "game loop \n"<< std::endl;
    if(Game::GetCurrentState()->GetQuitRequested() == true){
      std::cout << "quitrequested"<< std::endl;
      this->stateStack.pop();
      if(this->storedState != nullptr){
        stateStack.emplace(this->storedState);
        Game::GetCurrentState()->Start();
      }
    }
    this->CalculateDeltaTime();
    inputManager->Update();
    Game::GetCurrentState()->Update();
    Game::GetCurrentState()->Render();
    SDL_RenderPresent(renderer);
    SDL_Delay(33);
  }
}

SDL_Renderer* Game::GetRenderer(){
    return this->renderer;
}

void Game::CalculateDeltaTime(){
  float lastFrame = this->frameStart;
  this->frameStart = SDL_GetTicks();
  this->dt = (float) (this->frameStart - lastFrame)/1000;
}

float Game::GetDeltaTime(){
  return dt;
}

void Game::Push(State* state){
  this->storedState = state;
}

int main (int argc, char** argv) {
    argv = argv;
    argc = argc;

    Game* instance = Game::GetInstance();
    instance->Push(new FantomeState());
    //instance->Push(new StageState());
    instance->Game::Run();

    return 0;
}
