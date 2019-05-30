#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include"InputManager.h"
#include"Sprite.h"
#include"GAME.h"
#include"Resource.h"


void Sprite::Open(std::string file){
	this->texture = Resource::GetImage(file);
	SDL_QueryTexture(this->texture, nullptr, nullptr,&this->height ,&this->width);
	this->height = this->height/this->frameCount;
	//std::cout << "width = "<<this->height << std::endl;
	SetClip(0, 0, this->Sprite::GetHeight() ,this->Sprite::GetWidth());
}

Sprite::Sprite(){
	this->texture = nullptr;
	this->secondsToSelfDestruct = 0;
	this->frameCount = 1;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->frameTime = 1;
}

Sprite::Sprite(std::string file){
	this->texture = (nullptr);
	this->secondsToSelfDestruct = 0;
	this->frameCount = 1;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->frameTime = 1;
	Open(file);
}

Sprite::Sprite(GameObject* associated, int frameCount,float frameTime){
	this->texture = (nullptr);
	this->secondsToSelfDestruct = 0;
	this->associated = associated;
	this->frameCount = frameCount;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->frameTime = frameTime;
}


Sprite::~Sprite(){
	//SDL_DestroyTexture(this->texture);
}

void Sprite::Render(){
	Game* instace = Game::getInstance();
  	SDL_Rect dstrect;
  	dstrect.h = this->clipRect.h;
  	dstrect.w = this->clipRect.w;
  	dstrect.x = this->associated->box.x;
  	dstrect.y = this->associated->box.y;
  	SDL_RenderCopyEx(instace->getRenderer(), this->texture, &this->clipRect, &dstrect,this->associated->angleDeg,0,SDL_FLIP_NONE);

}

void Sprite::Render(float x, float y){
	Game* instace = Game::getInstance();
	//Component* componente = associated.GetComponent("");
  SDL_Rect dstrect;
  dstrect.h = this->clipRect.h;
  dstrect.w = this->clipRect.w;
  dstrect.x = x;
  dstrect.y = y;

  SDL_RenderCopyEx(instace->getRenderer(), this->texture, &this->clipRect, &dstrect,this->associated->angleDeg,0,SDL_FLIP_NONE);
}

void Sprite::Start(){

}

void Sprite::Update(float dt){
	InputManager* inputManager = InputManager::GetInstance();
	if(inputManager->KeyRelease(SDLK_a) == false){
    this->associated->box.x = this->associated->box.x + dt;
  }
  if(inputManager->KeyRelease(SDLK_d) == false){
    this->associated->box.x = this->associated->box.x - dt;
  }/*
  if(inputManager->KeyRelease(SDLK_w) == false){
    this->associated->box.y = this->associated->box.y + dt;
  }
  if(inputManager->KeyRelease(SDLK_s) == false){
    this->associated->box.y = this->associated->box.y - dt;
  }
*/
	this->timeElapsed = this->timeElapsed + dt;
	if(this->timeElapsed >= this->frameTime){
		this->timeElapsed = 0;
		this->currentFrame++;
		if(this->currentFrame >= this->frameCount){
			this->currentFrame = 0;
		}
		SetClip(this->Sprite::GetHeight()*this->currentFrame, 0, this->Sprite::GetHeight() ,this->Sprite::GetWidth());
	}

	if(this->secondsToSelfDestruct > 0){
		this->selfDestructCount.Update(dt);
		if(this->secondsToSelfDestruct <= this->selfDestructCount.Get()){
			this->associated->RequestDelete();
		}
	}
}

void Sprite::SetClip(int x, int y,int w,int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}


int Sprite::GetWidth(){
	return this->width*this->scale.x;
}

int Sprite::GetHeight(){
	return this->height*this->scale.y;
}

bool Sprite::IsOpen(){
	if(this->texture == nullptr){
		return true;
	}else{
		return false;
	}
}

bool Sprite::Is(std::string type){
	if(type == "Sprite"){
		return true;
	}else{
		return false;
	}
}
void Sprite::SetScaleX(float scaleX){
	this->scale.x = scaleX;
}

void Sprite::SetScaleY(float scaleY){
	this->scale.y = scaleY;
}

Vec2 Sprite::GetScale(){
	return this->scale;
}


void Sprite::SetFrame(int frame){
	this->currentFrame = frame;
	SetClip(this->Sprite::GetHeight()*this->currentFrame, 0, this->Sprite::GetHeight() ,this->Sprite::GetWidth());
}


void Sprite::SetFrameCount(int frameCount){
	this->height = this->height*this->frameCount;
	this->height = this->height/frameCount;
	this->frameCount = frameCount;
	this->currentFrame = 0;
}


void Sprite::SetFrameTime(float frameTime){
	this->frameTime = frameTime;
}
