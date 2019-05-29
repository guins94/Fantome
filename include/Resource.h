#pragma once

#include"Music.h"
#include"Sound.h"
#include"Text.h"

#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include<unordered_map>

class Resource{
private:
    static std::unordered_map<std::string, SDL_Texture*> imageTable;
    static std::unordered_map<std::string, Mix_Music*> musicTable;
    static std::unordered_map<std::string, Mix_Chunk*> soundTable;
    static std::unordered_map<std::string, TTF_Font*> fontTable;
  public:
    static SDL_Texture* GetImage(std::string file);
  public:
    static void ClearImages();
  public:
    static Mix_Music* GetMusic(std::string file);
  public:
    static void ClearMusics();
  public:
    static Mix_Chunk* GetSound(std::string file);
  public:
    static void ClearSounds();
  public:
    static TTF_Font* GetFont(std::string file,int size);
  public:
    static void ClearFont();
};
