#pragma once

#include "SDL2/SDL_mixer.h"
#include<iostream>

class Music{
	private:
		Mix_Music* music;

	public:
		Music();
	public:
		Music(std::string file);
	public:
		void Play(int times = -1);
	public:
		void Stop(int msToStop = 1500);
	public:
		void Open(std::string file);
	public:
		bool IsOpen();
};