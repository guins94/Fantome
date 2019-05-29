
#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include"Resource.h"
#include"Music.h"
#include"Sound.h"
#include"Sprite.h"
#include"GAME.h"

#include"Text.h"
#include<unordered_map>
#include "SDL2/SDL_mixer.h"
#include"Music.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

std::unordered_map<std::string, SDL_Texture*> Resource::imageTable;
std::unordered_map<std::string, Mix_Music*> Resource::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resource::soundTable;
std::unordered_map<std::string, TTF_Font*> fontTable;

//Resource* Resource::resource = NULL;
SDL_Texture* Resource::GetImage(std::string file){
  SDL_Texture* texture;
  int flag = 0;
  for ( auto it = imageTable.begin(); it != imageTable.end(); ++it ){
    if(imageTable.find(file) == it)
      flag = 1;
  }


  if(flag == 0){
    Game* instance = Game::getInstance();
  	SDL_Renderer* renderer = instance->getRenderer();
    texture = IMG_LoadTexture(renderer,file.c_str());
  }else{
    return imageTable.at(file);
  }

  imageTable.insert({file, texture});
  return texture;
}

void Resource::ClearImages(){
      for ( auto it = imageTable.begin(); it != imageTable.end(); ++it )
        SDL_DestroyTexture((*it).second);
      imageTable.clear();
}

Mix_Music* Resource::GetMusic(std::string file){
  Mix_Music* music;
  int flag = 0;
  for ( auto it = musicTable.begin(); it != musicTable.end(); ++it ){
    if(musicTable.find(file) == it)
      flag = 1;
  }
  if(flag == 0){
    music = Mix_LoadMUS(file.c_str());
  }else{
    return musicTable.at(file);
  }

  musicTable.insert({file, music});
  return music;
}

void Resource::ClearMusics(){

}

Mix_Chunk* Resource::GetSound(std::string file){
  Mix_Chunk* sound;
  int flag = 0;
  for ( auto it = soundTable.begin(); it != soundTable.end(); ++it ){
    if(soundTable.find(file) == it)
      flag = 1;
  }
  if(flag == 0){
    sound = Mix_LoadWAV(file.c_str());
  }else{
    return soundTable.at(file);
  }

  soundTable.insert({file, sound});
  return sound;

}

void Resource::ClearSounds(){

}

TTF_Font* Resource::GetFont(std::string file,int size){
  TTF_Font* texture;/*
  int flag = 0;
  for ( auto it = fontTable.begin(); it != fontTable.end(); ++it ){
    if(fontTable.find(file) == it)
      flag = 1;
  }


  if(flag == 0){
    Game* instance = Game::getInstance();
  	SDL_Renderer* renderer = instance->getRenderer();
    texture = TTF_OpenFont (file.c_str(), size);
  }else{
    return fontTable.at(file);
  }

  fontTable.insert({file, texture});*/
  return texture;
}

void Resource::ClearFont(){
      //for ( auto it = fontTable.begin(); it != fontTable.end(); ++it )
        //TTF_CloseFont ((*it).second);
      //fontTable.clear();
}
