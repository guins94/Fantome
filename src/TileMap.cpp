#include "TileMap.h"

TileMap::TileMap(GameObject* associated,std::string file,TileSet* tileSet){
  this->associated = associated;
	this->tileSet = tileSet;
  this->goCollider = nullptr;
	TileMap::Load(file);
  this->createCollision = false;
}

TileMap::TileMap(GameObject* associated,std::string file, TileSet* tileSet, bool createCollision){
  this->associated = associated;
	this->tileSet = tileSet;
  this->goCollider = nullptr;
  this->createCollision = false;
  if(createCollision) SetCollider();
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

int* TileMap::At(int x, int y, int z){
	if(-1 >= x || x >= 50){
		return nullptr;
	}
	if(-1 >= y || y >= 30){
		return nullptr;
	}
  z = z;
	int position = (x)*this->mapWidth +(y);
	return &this->tileMatrix.at(position);
}

void TileMap::Render(){
	//int i = 1;
	//for(; i<=this->mapDepth;i++){
		//RenderLayer(i,camera->pos.x, camera->pos.y);
	//}
  RenderLayer(1, Camera::pos.x, Camera::pos.y);
  //RenderLayer(2, Camera::pos.x, Camera::pos.y);
  this->createCollision = false;
}

void TileMap::Start(){

}

void TileMap::RenderLayer(int layer, int cameraX, int CameraY){
	int i,j;
	int* index;
  layer = layer;
	//index = At(0,0,0);
	//this->tileSet->RenderTile(*(index),0*64,0*64);

  int tileWidth = this->tileSet->GetTileWidth();
  int tileHeight = this->tileSet->GetTileHeight();

	if(layer == 1){
		for(i=0; i<=29; i++){
			for(j=0;j<=29; j++){
				index = At(i,j,0);
				if(*(index) != (-1)){
					//std::cout << "camada i: " << i<< "camadaj:"<<j <<std::endl;
					this->tileSet->RenderTile(*(index),(j*tileWidth) + cameraX,(i*tileHeight) + CameraY);
          //if(this->createCollision) CreateCollider(*(index),(j*tileWidth) + cameraX - 130, (i*tileHeight) + CameraY -30);
        }
			}
		}
	}/*else{
		for(i=24; i<=49; i++){
			for(j=0;j<=24; j++){
				index = At(i,j,0);
				if(*(index) != -1){
					this->tileSet->RenderTile(*(index),((j)*tileWidth) + cameraX,(i-24)*tileHeight + CameraY + 175);
          if(this->createCollision) CreateCollider(*(index),((j)*tileWidth) + cameraX,(i-24)*tileHeight + CameraY -300);
				}
			}
		}
	}*/
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

void TileMap::CreateCollider(unsigned index, float x, float y){
  /* Se o índice for renderizar um espaço vazio, não é necessário um Collider */
  if(index == -1) return;

  if(!(this->goCollider))
  {
    std::cout << "Tilemap.cpp: Invalid GameObject pointer. Exiting." << '\n';
    exit(-1);
  }

  /* O índice 0 indica o início do chão */
  if(index == 0)
  {
    this->goCollider->box.x = x;
    this->goCollider->box.y = y;
  }

  if(index >= 0 && index <= this->tileSet->GetColumns() - 1)
  {
    this->goCollider->box.w += this->tileSet->GetTileWidth();
    this->goCollider->box.h = this->tileSet->GetTileHeight();
  }

  if(index == this->tileSet->GetColumns() - 1){
    /* O índice 2 indica o final do chão */

    /* Adicionando chão ao vetor de objetos */
    this->createCollision = false;
    Collider* tileCollider = new Collider(this->goCollider, Vec2(1,1), Vec2(0,0));
    this->goCollider->AddComponent(tileCollider);
    Ground* tileGround = new Ground(this->goCollider);
    this->goCollider->AddComponent(tileGround);
    Game::GetInstance()->GetCurrentState()->AddObject(this->goCollider);

    SetCollider();
  }
}

void TileMap::SetCollider(){
  GameObject* goCollider = new GameObject();
  this->goCollider = goCollider;
  this->goCollider->box.w = 0;
  this->goCollider->box.h = 0;
  this->createCollision = true;
}
