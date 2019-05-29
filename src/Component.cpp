#include<vector>
#include<iostream>
#include<memory>
#include<string>

#include"Component.h"

Component::Component(GameObject* associated){
	//this->GameObject = associated;
	this->associated = associated;
}

Component::~Component(){

}

Component::Component(){

}

void Component::Update (float dt){
	dt= dt;
}

void Component::Render(){

}

void Component::Start(){

}

bool Component::Is(std::string type){

}

void Component::NotifyCollision(GameObject& other){

}
