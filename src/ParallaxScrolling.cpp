#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<memory>
#include<string>

#include"Sprite.h"
#include"ParallaxScrolling.h"
#include"Camera.h"

ParallaxScrolling::ParallaxScrolling(GameObject* associated,float multiplier,std::string sprite_file, std::string file){
  this->associated = associated;
  this->multiplier = multiplier;
  this->tileSet = new Sprite();
  this->tileSet->Open(sprite_file);
  //this->associated->GameObject::AddComponent(backGround1_sprite);
  //ParallaxScrolling::Load(file);
}

void ParallaxScrolling::Load(std::string file){
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

void ParallaxScrolling::SetTileSet(Sprite* tileSet){
	this->tileSet = tileSet;
}

int* ParallaxScrolling::At(int x,int y, int z){
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

void ParallaxScrolling::Render(){
  Camera* camera = Camera::GetInstance();
  //RenderLayer(1,camera->pos.x, camera->pos.y);
  this->tileSet->SetClip(0,0,this->tileSet->GetHeight() ,600);
  this->tileSet->Render(multiplier*camera->pos.x,multiplier*camera->pos.y);
}


void ParallaxScrolling::RenderLayer(int layer, int cameraX, int CameraY){
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
					this->RenderTile(*(index),(j*1024) + cameraX,(i*600) + CameraY);
				}
			}
		}
	}
}


void ParallaxScrolling::Start(){

}

void ParallaxScrolling::Update(float dx){

}

bool ParallaxScrolling::Is(std::string type){

}

void ParallaxScrolling::RenderTile(unsigned index,float x,float y ){
  int tilex ,tiley;
  //std::cout <<"index = "<<index<<std::endl;

  if(index <= 5){
    tilex = index ;
    tiley = 0;
  }else{
    if(index<=11){
      tilex=index -6;
      tiley = 1;
    }else{
      tilex = index - 12;
      tiley = 2;
    }
  }
  //std::cout <<"tilex = "<<tilex<<std::endl;
  //std::cout <<"tiley = "<<tiley<<std::endl;
  this->tileSet->SetClip(tilex*600,tiley*1024,600,1024);
  //Face* face = (Face*)go->GetComponent("Face");
  this->tileSet->Render(x,y);
}
