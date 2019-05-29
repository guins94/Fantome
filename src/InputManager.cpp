#include "SDL2/SDL.h"

#include"InputManager.h"
#include"StageState.h"
#include"Face.h"
#include"Vec2.h"
#include"GAME.h"
#include"GameObject.h"

#include<iostream>
#include<vector>
#include<unordered_map>

InputManager::InputManager(){
  this->updateCounter = 0;
  this->quitRequested = false;
  this->mouseX = 0;
  this->mouseY = 0;
  int i;
  for(i = 0;i>=5;i++)
    this->mouseStageState[i] = false;
  for(i = 0;i>=5;i++)
    this->mouseUpdate[i] = 0;
}

//InputManager::~InputManager(){

//}

void InputManager::Update(){

  SDL_Event event;
  SDL_GetMouseState(&this->mouseX, &this->mouseY);
  this->updateCounter ++;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        if(event.key.repeat != 1){
          //std::cout  << "entrando1"<<std::endl;

          if( event.key.keysym.sym == SDLK_ESCAPE ) {
  				   this->quitRequested = true;
  			     }else{
                keyStageState.erase(event.key.keysym.sym);
                keyUpdate.erase(event.key.keysym.sym);
                keyStageState.insert({event.key.keysym.sym,true});
                keyUpdate.insert({event.key.keysym.sym,this->updateCounter});
                //std::cout  << "button"<<std::endl;
            }
        }
        break;
      case SDL_KEYUP:
        keyStageState.erase(event.key.keysym.sym);
        keyUpdate.erase(event.key.keysym.sym);
        keyStageState.insert({event.key.keysym.sym,false});
        keyUpdate.insert({event.key.keysym.sym,this->updateCounter});
        //std::cout  << "entrando2"<<std::endl;
        break;
      case SDL_MOUSEBUTTONDOWN:
        //std::cout  << "entrando3";
        //SDL_BUTTON_LEFT

        switch (event.button.button) {
          case SDL_BUTTON_LEFT:
          //std::cout  << "mouse esquerdo"<<std::endl;
            this->mouseStageState[0] = true;
            this->mouseUpdate[0] = this->updateCounter;
            break;
          case SDL_BUTTON_RIGHT:
          //std::cout  << "mouse direito"<<std::endl;
            this->mouseStageState[1] = true;
            this->mouseUpdate[1] = this->updateCounter;
            break;
          default:
            break;
          }
        break;
      case SDL_MOUSEBUTTONUP:
      switch (event.button.button) {
        case SDL_BUTTON_LEFT:
        //std::cout  << "mouse esquerdo"<<std::endl;
          this->mouseStageState[0] = false;
          this->mouseUpdate[0] = this->updateCounter;
          break;
        case SDL_BUTTON_RIGHT:
        //std::cout  << "mouse direito"<<std::endl;
          this->mouseStageState[1] = false;
          this->mouseUpdate[1] = this->updateCounter;
          break;
        default:
          break;
        }
        //std::cout  << "entrando4"<<std::endl;
        break;
      case SDL_QUIT:
        this->quitRequested = true;
        //std::cout  << "entrando5"<< std::endl;
        break;
      default:
        break;
      }
    }


    //for(i = 0;i>=5;i++)
      //this->mouseStageState[i] = false;

}


bool InputManager::KeyPress(int key){

    for ( auto iti = keyUpdate.begin(); iti != keyUpdate.end(); ++iti ){
      if(keyUpdate.find(key) == iti){
        std::unordered_map<int, int>::const_iterator goti = keyUpdate.find(key);
        if(this->updateCounter != goti->second){
          return false;
        }
        //std::cout  << "update "<< std::endl;
      }
    }

    for ( auto it = keyStageState.begin(); it != keyStageState.end(); ++it ){
      //std::cout  << "checando "<< std::endl;
      if(keyStageState.find(key) == it){
        std::unordered_map<int, bool>::const_iterator got = keyStageState.find(key);
        return got->second;
        //std::cout  << "ACHAMOS "<< std::endl;
      }
    }
    return false;
}

bool InputManager::KeyRelease(int key){

  for ( auto it = keyStageState.begin(); it != keyStageState.end(); ++it ){
    if(keyStageState.find(key) == it){
      std::unordered_map<int, bool>::const_iterator got = keyStageState.find(key);
      if(got->second == false)
        return true;
      else
        return false;
      //return got->second;
    }
  }
  return true;
}

bool InputManager::IsKeyDown(int key){
  for ( auto iti = keyUpdate.begin(); iti != keyUpdate.end(); ++iti ){
    if(keyUpdate.find(key) == iti){
      std::unordered_map<int, int>::const_iterator goti = keyUpdate.find(key);
      if(this->updateCounter == goti->second){
        return true;
      }
    }
  }

  return false;
}

bool InputManager::MousePress(int button){
  switch (button) {
    case SDL_BUTTON_LEFT:
    //std::cout  << "mouse esquerdo"<<std::endl;
    if(this->mouseUpdate[0] == this->updateCounter)
      return this->mouseStageState[0];
    break;
    case SDL_BUTTON_RIGHT:
      if(this->mouseUpdate[1] == this->updateCounter)
        return this->mouseStageState[1];
      break;
    default:
      break;
    }
    return false;
}

bool InputManager::MouseRelease(int button){
  switch (button) {
    case SDL_BUTTON_LEFT:
    //std::cout  << "mouse esquerdo"<<std::endl;
    if(this->mouseStageState[0] == false)
      return true;
    break;
    case SDL_BUTTON_RIGHT:
      if(this->mouseStageState[1] == false)
        return true;
      break;
    default:
      break;
    }
    return false;
}

bool InputManager::IsMouseDown(int button){
  switch (button) {
    case SDL_BUTTON_LEFT:
    //std::cout  << "mouse esquerdo"<<std::endl;
    if(this->mouseStageState[0] == false)
      return false;
    break;
    case SDL_BUTTON_RIGHT:
      if(this->mouseStageState[1] == false)
        return false;
      break;
    default:
      break;
    }
    return false;
}

int InputManager::GetMouseX(){
  return this->mouseX;
}

int InputManager::GetMouseY(){
  return this->mouseY;
}

bool InputManager::QuitRequested(){
  return this->quitRequested;
}

InputManager* InputManager::GetInstance(){
  static InputManager instance;
  return &instance;
}
