#include"TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file){
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	this->tileSet = new Sprite();
	this->tileSet->Open(file);
	this->rows = this->tileSet->GetWidth()/this->tileHeight;
  this->columns = this->tileSet->GetHeight()/this->tileWidth;

	if(this->rows <= 0){
		std::cout << "Tileset.cpp: Critical error. Invalid number of rows" << '\n';
		//exit(-1);
	}

	if(this->columns<=0){
		std::cout << "Tileset.cpp: Critical error. Invalid number of columns" << '\n';
		//exit(-1);
	}
}

void TileSet::RenderTile(unsigned index, float x, float y){
	int tilex ,tiley;
	//std::cout <<"index = "<<index<<std::endl;

	if(index <= 3){
		tilex = index ;
		tiley = 0;
	}else{
		if(index<=7){
			tilex=index -4;
			tiley = 1;
		}else{
			if(index<=11){
				tilex = index - 8;
				tiley = 2;
			}else{
				if(index<=15){
					tilex = index - 12;
					tiley = 3;
				}else{
					if(index<=19){
						tilex = index - 16;
						tiley = 4;
					}else{
						if(index<=23){
							tilex = index - 20;
							tiley = 5;
						}else{
							if(index<=27){
								tilex = index - 24;
								tiley = 6;
							}else{
								if(index<=31){
									tilex = index - 28;
									tiley = 7;
								}else{
									if(index<=35){
										tilex = index - 32;
										tiley = 8;
									}else{
										tilex = index - 36;
										tiley = 9;
									}
								}
							}
						}
					}
				}
			}
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

int TileSet::GetRows(){
	return this->rows;
}

int TileSet::GetColumns(){
	return this->columns;
}
