#pragma once

#include"SDL2/SDL_mixer.h"
#include"Component.h"
class Sound : public Component{
	private:
		Mix_Chunk* chunk;
		int channel;
	public:
		Sound(GameObject* associated);
	public:
		Sound(GameObject* associated, std::string  file);
	public:
		~Sound();
	public:
		void Play(int times = 1);
	public:
		void Stop();
	public:
		void Open(std::string file);
	public:
		bool IsOpen();
	public:
		void Update(float dt);
	public:
		void Render();
	public:
		void Start();
	public:
		bool Is(std::string type);

};
