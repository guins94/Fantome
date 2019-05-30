#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<memory>
#include<string>

#include"Sprite.h"
#include"TileMap.h"
#include"TileSet.h"
#include"Camera.h"

using namespace std;


TileMap::TileMap(GameObject* associated,std::string file,TileSet* tileSet){
  this->associated = associated;
	this->tileSet = tileSet;
	TileMap::Load(file);

}

void TileMap::Load(std::string file){
	//this->tileSet->tileSet->Open(file);

	std::ifstream File(file.c_str());
 	//File.open(file);
	std::string File_string;

 	if(File.is_open()) {
		getline(File, File_string,',');
		//std::cout << "altura é " << File_string <<std::endl;
		this->mapWidth = std::stoi(File_string);


		getline(File, File_string,',');
		//std::cout << "largura é " << File_string <<std::endl;
		this->mapHeight = std::stoi(File_string);

		getline(File, File_string,',');
		//std::cout << "profundidade é " << File_string <<std::endl;
		this->mapDepth = std::stoi(File_string);

		while(getline(File, File_string,',')){
			if(!File.eof()){

				//std::cout  << std::stoi(File_string)<< " "<<std::endl;
				this->tileMatrix.insert(tileMatrix.end(),std::stoi(File_string) - 1);
			}
 		}
	}
	File.close();
}

void TileMap::SetTileSet(TileSet* tileSet){
	this->tileSet = tileSet;
}

int* TileMap::At(int x,int y, int z){
	if(-1 >= x || x >= 50){
		return nullptr;
	}
	if(-1 >= y || y >= 25){
		return nullptr;
	}
  z = z;
	int position = (x)*this->mapWidth +(y);
	return &this->tileMatrix.at(position);
}

void TileMap::Render(){
	//int i = 1;
  Camera* camera = Camera::GetInstance();
	//for(; i<=this->mapDepth;i++){
		//RenderLayer(i,camera->pos.x, camera->pos.y);
	//}
  RenderLayer(1,camera->pos.x, camera->pos.y);
  RenderLayer(2,camera->pos.x, camera->pos.y);
}

void TileMap::Start(){

}

void TileMap::RenderLayer(int layer, int cameraX, int CameraY){
	int i,j;
	int* index;
  layer = layer;
	//index = At(0,0,0);
	//this->tileSet->RenderTile(*(index),0*64,0*64);

	if(layer == 1){
		for(i=0; i<=24; i++){
			for(j=0;j<=24; j++){
				index = At(i,j,0);
				if(*(index) != (-1)){
					//std::cout << "camada i: " << i<< "camadaj:"<<j <<std::endl;
					this->tileSet->RenderTile(*(index),(j*316) + cameraX,(i*143) + CameraY + 500);
				}
			}
		}
	}else{
		for(i=24; i<=49; i++){
			for(j=0;j<=24; j++){
				index = At(i,j,0);
				if(*(index) != -1){
					this->tileSet->RenderTile(*(index),((j)*316) + cameraX,(i-24)*143 + CameraY +500);
				}
			}
		}
	}
}

void TileMap::Update(float dx){
  //this->associated->box.x =
}

bool TileMap::Is(std::string type){
	if(type == "Tile"){
		return true;
	}else{
		return false;
	}
}

int TileMap::GetWidth(){
	return this->mapWidth;
}

int TileMap::GetHeight(){
	return this->mapHeight;
}

int TileMap::GetDepth(){
	return this->mapDepth;
}

int ParallaxScolling(int layer){

}
