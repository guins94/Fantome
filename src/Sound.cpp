#include"Sound.h"

Sound::Sound(GameObject* associated){
	this->associated = associated;
	this->chunk =nullptr;
}

Sound::Sound(GameObject* associated, std::string  file){
	this->associated = associated;
	this->chunk =nullptr;
	Open(file);
}

Sound::~Sound(){
	if(this->chunk != nullptr){
		Mix_HaltChannel(this-> channel);
		Mix_FreeChunk(this->chunk);
	}
}

void Sound::Play(int times ){
	times = times;
	this->channel = Mix_PlayChannel(-1, this->chunk,0);
}

void Sound::Stop(){
	Mix_HaltChannel(this->channel);
}

void Sound::Open(std::string file){
	this->chunk = Resources::GetSound(file);
}

bool Sound::IsOpen(){
	if(this->chunk == nullptr){
		return true;
	}else{
		return false;
	}
}

void Sound::Update(float dt){
	dt = dt;
}

void Sound::Render(){

}

void Sound::Start(){

}

bool Sound::Is(std::string type){
	if(type == "Sound")
		return true;
	else
		return false;
}
