#include "Sprite.h"

void Sprite::Open(std::string file){
	this->texture = Resources::GetImage(file);
	SDL_QueryTexture(this->texture, nullptr, nullptr,&this->height ,&this->width);
	this->height = this->height/this->frameCount;
	SetClip(0, 0, this->Sprite::GetHeight(), this->Sprite::GetWidth());
}

Sprite::Sprite(){
	this->texture = nullptr;
	this->secondsToSelfDestruct = 0;
	this->frameCount = 1;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->frameTime = 1;
	this->isRenderEnabled = true;
	this->isFlipped = false;
	this->willFreeze = false;
	this->hasFreezed = false;
}

Sprite::Sprite(std::string file){
	this->texture = (nullptr);
	this->secondsToSelfDestruct = 0;
	this->frameCount = 1;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->frameTime = 1;
	this->isRenderEnabled = true;
	this->isFlipped = false;
	this->willFreeze = false;
	this->hasFreezed = false;
	this->fileName = file;
	Open(file);
}

Sprite::Sprite(GameObject* associated, int frameCount, float frameTime)
{
	this->associated = associated;

	this->texture = (nullptr);
	this->scale = Vec2(1,1);
	this->frameCount = frameCount;
	this->frameTime = frameTime;
	this->currentFrame = 0;
	this->timeElapsed = 0;
	this->isRenderEnabled = true;
	this->isFlipped = false;
	this->secondsToSelfDestruct = 0;
	this->willFreeze = false;
	this->hasFreezed = false;
}

Sprite::Sprite(GameObject* associated, std::string file, int frameCount, float frameTime, float secondsToSelfDestruct)
{
  this->associated = associated;

  this->texture = nullptr;
  this->scale = Vec2(1,1);
  this->frameCount = frameCount;
  this->frameTime = frameTime;
  this->currentFrame = 0;
  this->timeElapsed = 0;
	this->isRenderEnabled = true;
	this->isFlipped = false;
  this->secondsToSelfDestruct = secondsToSelfDestruct;
  this->selfDestructCount.Restart();
	this->willFreeze = false;
	this->hasFreezed = false;
	this->fileName = file;
  Open(file);
}


Sprite::~Sprite(){
	//SDL_DestroyTexture(this->texture);
}

void Sprite::Render(){

	/* If render is not enabled, return */
	if(!isRenderEnabled) return;

  SDL_Rect dstrect;
  dstrect.h = this->clipRect.h;
  dstrect.w = this->clipRect.w;
  dstrect.x = this->associated->box.x + Camera::pos.x;
  dstrect.y = this->associated->box.y + Camera::pos.y;

	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	if(isFlipped) flipType = SDL_FLIP_HORIZONTAL;

	if(SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), this->texture, &this->clipRect, &dstrect, this->associated->angleDeg, nullptr, flipType) != 0) {
      SDL_Log("Unable to initialize SDL_RenderCopyEx: %s", SDL_GetError());
			std::cout << "File Name: " << this->fileName << '\n';
      exit(-1);
  }
}

void Sprite::Render(float x, float y){

	/* If render is not enabled, return */
	if(!isRenderEnabled) return;

	SDL_Rect dstrect;
  dstrect.h = this->clipRect.h;
  dstrect.w = this->clipRect.w;
  dstrect.x = x;
  dstrect.y = y;

	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	if(isFlipped) flipType = SDL_FLIP_HORIZONTAL;

	if (SDL_RenderCopyEx(Game::GetInstance()->GetRenderer(), this->texture, &this->clipRect, &dstrect, 0, nullptr, flipType) != 0) {
      SDL_Log("Unable to initialize SDL_RenderCopyEx: %s", SDL_GetError());
			std::cout << "File Name: " << this->fileName << '\n';
      exit(-1);
  }
}

void Sprite::Start(){

}

void Sprite::Update(float dt)
{
	/* Retrieving Input Manager Instance */
	InputManager* inputManager = InputManager::GetInstance();

	this->timeElapsed = this->timeElapsed + dt;
	if(this->timeElapsed >= this->frameTime){
		this->timeElapsed = 0;
		this->currentFrame++;
		if(this->currentFrame >= this->frameCount && !this->willFreeze)
		{
			this->currentFrame = 0;
		}
		if(this->currentFrame == this->freezedFrame && this->willFreeze)
		{
			this->hasFreezed = true;
			this->currentFrame = this->freezedFrame;
		}
		if(this->hasFreezed)
		{
			this->currentFrame = this->freezedFrame;
		}
		SetClip(this->Sprite::GetHeight()*this->currentFrame, 0, this->Sprite::GetHeight(), this->Sprite::GetWidth());
	}

	if(this->secondsToSelfDestruct > 0){
		this->selfDestructCount.Update(dt);
		if(this->selfDestructCount.Get() >= this->secondsToSelfDestruct){
			this->associated->RequestDelete();
		}
	}
}

void Sprite::SetClip(int x, int y, int w, int h){
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

bool Sprite::IsFlipped()
{
	return this->isFlipped;
}

bool Sprite::Is(std::string type)
{
	return (type == "Sprite");
}

void Sprite::EnableRender()
{
	this->isRenderEnabled = true;
}

void Sprite::DisableRender()
{
	this->isRenderEnabled = false;
}

void Sprite::EnableFlip()
{
	this->isFlipped = true;
}

void Sprite::DisableFlip()
{
	this->isFlipped = false;
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

void Sprite::FreezeFrame(int freeze)
{
	this->willFreeze = true;
	this->freezedFrame = freeze;
}

void Sprite::ResetFreeze()
{
	this->willFreeze = false;
	this->hasFreezed = false;
	this->freezedFrame = -1;
}
