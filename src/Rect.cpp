#include "Rect.h"

Rect::Rect(){

}

bool Rect::Contains(float x, float y){
	if( x >= this->x && x <= this->x + this->w)
		if(y >= this->y && y <= this->y + this->h)
			return true;

	return false;
}

Vec2 Rect::GetCenter(){
  /* Obter coordenadas do centro do retângulo */
  float centerX = (this->x + this->w/2);
  float centerY = (this->y + this->h/2);
  return Vec2(centerX, centerY);
}
