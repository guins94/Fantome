#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef GAME_HEADER
#define GAME_HEADER

class Game
{
    private:
      static Game* instance;

      SDL_Window* window;
      SDL_Renderer* renderer;
      State* storedState;
      std::stack<std::unique_ptr<State>> stateStack;

      int frameStart;
      float dt;

    	Game(const char* title, int width, int height);
      void CalculateDeltaTime();

    public:
      int width;
      int height;

    	~Game();

      static Game* GetInstance();
      State* GetCurrentState();
    	SDL_Renderer* GetRenderer();

      float GetDeltaTime();

      void Run();
      void Push(State* stored);
};

#endif
