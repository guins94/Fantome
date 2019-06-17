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
      int frameStart;
      float dt;
      void CalculateDeltaTime();
    	Game(const char* title, int width,int height);
      std::stack<std::unique_ptr<State>> stateStack;
      //std::stack<State*> stateStack;
    public:
    	~Game();

    public:
        /* Static access method. */
        static Game* GetInstance();

    public:
        /* Static access method. */
        State* GetCurrentState();

    public:
    	void Run();

    public:
    	SDL_Renderer* GetRenderer();

    public:
      float GetDeltaTime();
    public:
      void Push(State* stored);
    public:
      int width;
      int height;

};

#endif
