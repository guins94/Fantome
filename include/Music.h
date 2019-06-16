#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef MUSIC_HEADER
#define MUSIC_HEADER

class Music{
	private:
		Mix_Music* music;

	public:
		Music();
	public:
		Music(std::string file);
	public:
		~Music();
	public:
		void Play(int times = -1);
	public:
		void Stop(int msToStop = 1500);
	public:
		void Open(std::string file);
	public:
		bool IsOpen();
};

#endif
