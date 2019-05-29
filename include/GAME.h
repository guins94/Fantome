#pragma once

#include"StageState.h"
#include"State.h"

#include<iostream>
#include<string.h>
#include <stack>
#include<memory>

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
        static Game* getInstance();

    public:
        /* Static access method. */
        State* getStageState();

    public:
    	void Run();

    public:
    	SDL_Renderer* getRenderer();

    public:
      float GetDeltaTime ();
    public:
      void Push(State* stored);
};
