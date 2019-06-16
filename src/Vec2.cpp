#include "Vec2.h"

Vec2::Vec2(){
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y){
	this->x = x;
	this->y = y;
}

Vec2 Vec2::GetRotated(float angle){

  float cs = cos(angle);
  float sn = sin(angle);

  float resultX = ((this->x)*cs) - ((this->y)*sn);
  float resultY = ((this->y)*cs) + ((this->x)*sn);

  return Vec2(resultX, resultY);
}


void Vec2::Speed(float x, float y, int mouseX, int mouseY){
	float distanceX = mouseX - x;
	float velocityX = distanceX/30;
	this->x = velocityX;
	float distanceY = y - mouseY;
	float velocityY = distanceY/30;
	this->y=velocityY;
}
