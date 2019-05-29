#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include"StageState.h"
#include"Sprite.h"
#include"TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file){
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	this->tileSet = new Sprite();
	this->tileSet->Open(file);
  this->rows = this->tileSet->GetHeight()/this->tileWidth;
  this->columns = this->tileSet->GetWidth()/this->tileHeight;
}

void TileSet::RenderTile(unsigned index,float x,float y ){
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
	this->tileSet->SetClip(tilex*GetTileWidth(),tiley*GetTileHeight(),GetTileWidth(),GetTileHeight());
	//Face* face = (Face*)go->GetComponent("Face");
	this->tileSet->Render(x,y);

}

int TileSet::GetTileWidth(){
	return this->tileWidth;
}


int TileSet::GetTileHeight(){
	return this->tileHeight;
}
