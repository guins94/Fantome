#include"Vec2.h"
#include<iostream>
#include<memory>
#include<string>


Vec2::Vec2(float x, float y){
	this->x = x;
	this->y = y;
}


void Vec2::GetRotated(float angle){
	//std::cout << "rotation"<<std::endl;
	this->x = cos(angle);
	this->y = sin(angle);
	//std::cout << cos(angle)<<std::endl;
}


void Vec2::Speed(float x, float y, int mouseX, int mouseY){
	float distanceX = mouseX - x;
	float velocityX = distanceX/30;
	this->x=velocityX;
	float distanceY = y - mouseY;
	float velocityY = distanceY/30;
	this->y=velocityY;
}
