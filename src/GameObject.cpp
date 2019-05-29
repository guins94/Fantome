#include<vector>
#include<iostream>
#include<memory>
#include<string>
#include<algorithm>

#include"GameObject.h"
#include"Component.h"

GameObject::GameObject(){
	this->isDead = false;
	this->started = false;
	this->angleDeg = 0;
}

GameObject::~GameObject(){
	this->components.clear();
}

void GameObject::Update(float dt){
	//for(std::vector <Component*>::iterator it = this->components.begin(); it!=this->components.end(); it++){
		//(*it)->Update(dt);
	//}
	for(int x = 0; x<=this->components.size() - 1; x++){
    components[x]->Update(dt);
  }
}

void GameObject::Render(){
	//for(std::vector <Component*>::iterator it = this->components.begin(); it!=this->components.end(); it++){
		//(*it)->Render();
	//}
	for(int x = 0; x<=this->components.size() - 1; x++){
    components[x]->Render();
  }
}

void GameObject::Start(){
	if(this->started == false){
		//for(std::vector <Component*>::iterator it = this->components.begin(); it!=this->components.end(); it++){
			//(*it)->Start();
		//}
		for(int i = 0;i <= this->components.size() - 1; i++){
	    this->components[i]->Start();
	  }
	}
	this->started = true;
}

bool GameObject::IsDead(){
	return this->isDead;
}

void GameObject::RequestDelete(){
	this->isDead = true;
}

void GameObject::AddComponent(Component* cpt){
	this->components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
	if ( std::find(this->components.begin(), this->components.end(), cpt) != this->components.end()){
   		this->components.erase(std::remove(this->components.begin(), this->components.end(), cpt), this->components.end());
   	}

}

Component* GameObject::GetComponent(std::string type){
	//for(std::vector <Component*>::iterator it = this->components.begin(); it!=this->components.end(); it++){
		//if((*it)->Is(type) == true){
			//return (*it);
		//}
	//}
	//return nullptr;
	for(int x = 0; x<=this->components.size() - 1; x++){
		if(components[x]->Is(type) == true){
			return components[x];
		}
	}
		return nullptr;
}

int GameObject::SizeComponent(){
	return this->components.size();
}

void GameObject::NotifyCollision(GameObject& other){
	for(int x = 0; x<=this->components.size() - 1; x++){
		components[x]->NotifyCollision(other);
	}
}
