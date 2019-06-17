#include "Surface.h"

Surface::Surface(GameObject* associated){
  this->associated = associated;

}

void Surface::Load(std::string file){
}

int* Surface::At(int x,int y, int z){

}

void Surface::Render(){

}

void Surface::Start(){

}

void Surface::RenderLayer(int layer, int cameraX, int CameraY){

}

void Surface::Update(float dt){

}

bool Surface::Is(std::string type){
	if(type == "Surface"){
		return true;
	}else{
		return false;
	}
}
