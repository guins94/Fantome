#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include "SDL2/SDL_mixer.h"
#include"Music.h"
#include"Resource.h"
Music::Music(){
	this->music = nullptr;
}

Music::Music(std::string file){
	this->Open(file);
}

void Music::Play(int times){
	if(this->music == nullptr){
		Music *music = new Music();
    	music->Open("assets/audio/stageStageState.ogg");
	}
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
	this->music = Resource::GetMusic(file);
}

bool Music::IsOpen(){
	if(this->music == nullptr){
		return true;
	}else{
		return false;
	}
}
