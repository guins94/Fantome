#include "Resources.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;
std::unordered_map<std::string, TTF_Font*> fontTable;

//Resources* Resources::Resources = NULL;
SDL_Texture* Resources::GetImage(std::string file){
  SDL_Texture* texture;
  int flag = 0;
  for ( auto it = imageTable.begin(); it != imageTable.end(); ++it ){
    if(imageTable.find(file) == it)
      flag = 1;
  }


  if(flag == 0){
    Game* instance = Game::GetInstance();
  	SDL_Renderer* renderer = instance->GetRenderer();
    texture = IMG_LoadTexture(renderer,file.c_str());
  }else{
    return imageTable.at(file);
  }

  imageTable.insert({file, texture});
  return texture;
}

void Resources::ClearImages(){
      for ( auto it = imageTable.begin(); it != imageTable.end(); ++it )
        SDL_DestroyTexture((*it).second);
      imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
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

void Resources::ClearMusics(){

}

Mix_Chunk* Resources::GetSound(std::string file){
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

void Resources::ClearSounds(){

}

TTF_Font* Resources::GetFont(std::string file,int size){
  TTF_Font* texture;/*
  int flag = 0;
  for ( auto it = fontTable.begin(); it != fontTable.end(); ++it ){
    if(fontTable.find(file) == it)
      flag = 1;
  }


  if(flag == 0){
    Game* instance = Game::GetInstance();
  	SDL_Renderer* renderer = instance->GetRenderer();
    texture = TTF_OpenFont (file.c_str(), size);
  }else{
    return fontTable.at(file);
  }

  fontTable.insert({file, texture});*/
  return texture;
}

void Resources::ClearFont(){
      //for ( auto it = fontTable.begin(); it != fontTable.end(); ++it )
        //TTF_CloseFont ((*it).second);
      //fontTable.clear();
}
