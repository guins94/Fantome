#include "Music.h"

Music::Music(){
	this->music = nullptr;
}

Music::Music(std::string file){
	this->Open(file);
}

Music::~Music(){
	Stop(1500);
	Mix_FreeMusic(this->music);
}

void Music::Play(int times){
	if(this->music == nullptr){
		exit(-1);
	}
	Mix_PlayMusic(this->music, times);
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
	this->music = Resources::GetMusic(file);
}

bool Music::IsOpen(){
	if(this->music == nullptr){
		return true;
	}else{
		return false;
	}
}
