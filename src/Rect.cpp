#include"Rect.h"

#include"Vec2.h"

Rect::Rect(){

}

bool Rect::Contains(float x, float y){
	if( x >= this->x && x<= this->x + this->w)
		if(y >= this->y && y<= this->y + this->h)
			return true;

	return false;
}

Vec2 Rect::GetCenter(){
	Vec2 center(this->x, this->y );
	return center;
}
